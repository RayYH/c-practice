/**
 * @see https://www.ibm.com/docs/en/i/7.4?topic=apis-example-client-request-file
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>

#define SERVER_PORT 12345

int main(void) {
  int i, len, rc, on = 1;
  int sock_fd, max_sd, new_sd;
  int desc_ready, end_server = false;
  int close_conn;
  char buffer[80];
  struct sockaddr_in6 addr;
  struct timeval timeout;
  fd_set master_set, working_set;

  /* Create an AF_INET6 stream socket to receive incoming connections on. */
  sock_fd = socket(AF_INET6, SOCK_STREAM, 0);
  if (sock_fd == -1) {
    perror("socket() failed");
    exit(-1);
  }

  /* Allow socket descriptor to be reusable. SOL_SOCKET means manipulate
   * options at the sockets API level. */
  rc = setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof(on));
  if (rc == -1) {
    perror("setsockopt() failed");
    close(sock_fd);
    exit(-1);
  }

  /* Set socket to be nonblocking. All of the sockets for the incoming
   * connections will also be nonblocking since they will inherit that state
   * from the listening socket. */
  rc = ioctl(sock_fd, FIONBIO, (char *) &on);
  if (rc < 0) {
    perror("ioctl() failed");
    close(sock_fd);
    exit(-1);
  }

  /* Bind the socket. */
  memset(&addr, 0, sizeof(addr));
  addr.sin6_family = AF_INET6;
  memcpy(&addr.sin6_addr, &in6addr_any, sizeof(in6addr_any));
  addr.sin6_port = htons(SERVER_PORT);
  rc = bind(sock_fd, (struct sockaddr *) &addr, sizeof(addr));
  if (rc < 0) {
    perror("bind() failed");
    close(sock_fd);
    exit(-1);
  }

  /* Set the listen back log. */
  rc = listen(sock_fd, 32);
  if (rc < 0) {
    perror("listen() failed");
    close(sock_fd);
    exit(-1);
  }

  /* Initialize the master fd_set. */
  FD_ZERO(&master_set);
  max_sd = sock_fd;
  FD_SET(sock_fd, &master_set);

  /* Initialize the timeval struct to 3 minutes. If no activity after 3
   * minutes this program will end. */
  timeout.tv_sec = 3 * 60;
  timeout.tv_usec = 0;

  /* Loop waiting for incoming connects or for incoming data on any of the
   * connected sockets. */
  do {
    /* Copy the master fd_set over to the working fd_set. */
    memcpy(&working_set, &master_set, sizeof(master_set));

    /* Call select() and wait 3 minutes for it to complete. */
    printf("Waiting on select()...\n");
    rc = select(max_sd + 1, &working_set, NULL, NULL, &timeout);

    /* Check to see if the select call failed. */
    if (rc < 0) {
      perror("  select() failed");
      break;
    }

    /* Check to see if the 3 minute time out expired. */
    if (rc == 0) {
      printf("  select() timed out. End program.\n");
      break;
    }

    /* One or more descriptors are readable. Need to determine which ones
     * they are. */
    desc_ready = rc;
    for (i = 0; i <= max_sd && desc_ready > 0; ++i) {
      /* Check to see if this descriptor is ready. */
      if (FD_ISSET(i, &working_set)) {
        /* A descriptor was found that was readable - one less has to be
         * looked for. This is being done so that we can stop looking at the
         * working set once we have found all of the descriptors that were
         * ready. */
        desc_ready -= 1;

        /* Check to see if this is the listening socket. */
        if (i == sock_fd) {
          printf("  Listening socket is readable\n");
          /* Accept all incoming connections that are queued up on the
           * listening socket before we loop back and call select again. */
          do {
            /* Accept each incoming connection. If accept fails with
             * EWOULDBLOCK, then we have accepted all of them. Any other
             * failure on accept will cause us to end the server. */
            new_sd = accept(sock_fd, NULL, NULL);
            if (new_sd < 0) {
              if (errno != EWOULDBLOCK) {
                perror("  accept() failed");
                end_server = true;
              }
              break;
            }

            /* Add the new incoming connection to the master read set. */
            printf("  New incoming connection - %d\n", new_sd);
            FD_SET(new_sd, &master_set);
            if (new_sd > max_sd) {
              max_sd = new_sd;
            }

            /* Loop back up and accept another incoming connection. */
          } while (new_sd != -1);
        } else { /* This is not the listening socket, therefore an existing
                  * connection must be readable. */
          printf("  Descriptor %d is readable\n", i);
          close_conn = false;
          /* Receive all incoming data on this socket before we loop back and
           * call select again. */
          do {
            /* Receive data on this connection until the recv fails with
             * EWOULDBLOCK.  If any other failure occurs, we will close the
             * connection. */
            rc = recv(i, buffer, sizeof(buffer), 0);
            if (rc < 0) {
              if (errno != EWOULDBLOCK) {
                perror("  recv() failed");
                close_conn = true;
              }
              break;
            }

            /* Check to see if the connection has been closed by the client. */
            if (rc == 0) {
              printf("  Connection closed\n");
              close_conn = true;
              break;
            }

            /* Data was received. */
            len = rc;
            printf("  %d bytes received\n", len);

            /* Echo the data back to the client. */
            rc = send(i, buffer, len, 0);
            if (rc < 0) {
              perror("  send() failed");
              close_conn = true;
              break;
            }

          } while (true);

          /* If the close_conn flag was turned on, we need to clean up this
           * active connection. This clean up process includes removing the
           * descriptor from the master set and determining the new maximum
           * descriptor value based on the bits that are still turned on in
           * the master set. */
          if (close_conn) {
            close(i);
            FD_CLR(i, &master_set);
            if (i == max_sd) {
              while (FD_ISSET(max_sd, &master_set) == false)
                max_sd -= 1;
            }
          }
        } /* End of existing connection is readable */
      } /* End of if (FD_ISSET(i, &working_set)) */
    } /* End of loop through selectable descriptors */

  } while (end_server == false);

  /* Clean up all of the sockets that are open. */
  for (i = 0; i <= max_sd; ++i) {
    if (FD_ISSET(i, &master_set)) {
      close(i);
    }
  }

  return 0;
}
