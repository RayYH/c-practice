#include "stdio.h"
#include "assert.h"
#include "string.h"

#define END printf("\n\n");

/*
 ***********************************************************************************************************************
 *
 * Useful Links:
 *
 * https://www.geeksforgeeks.org/return-values-of-printf-and-scanf-in-c-cpp/
 * https://www.geeksforgeeks.org/g-fact-11/
 * https://www.geeksforgeeks.org/scansets-in-c/
 * https://www.geeksforgeeks.org/gets-is-risky-to-use/
 * https://www.geeksforgeeks.org/puts-vs-printf-for-printing-a-string/
 * https://www.geeksforgeeks.org/g-fact-31/
 * http://swoolley.org/man.cgi/3/printf
 * https://www.geeksforgeeks.org/how-to-print-using-printf/
 *
 ***********************************************************************************************************************
 */

void io_basic() {
    char *str = "Press Ctrl+Z (windows) or Ctrl+D (Linux/OSX) to exit this echo program:\n";
    // printf returns total number of Characters Printed
    assert(printf("%s", str) == strlen(str));
    // scanf returns total number of Inputs Scanned successfully,

    // return type of getchar(), fgetc() and getc() is int, not char
    // EOF is a minus int - usually `-1`
    int in;
    while ((in = getchar()) != EOF) {
        putchar(in);
    }
}

void scanf_usage() {
    char str[128];

    printf("Enter a string (e.g. RAY_HONG): ");
    // store only capital letters to character array str
    scanf("%[A-Z]s", str);
    printf("You entered: %s\n", str);
    fflush(stdin);

    char str2[128];
    printf("Enter a string (e.g. hello): ");
    // read all characters but stops after first occurrence of `o` (o is not included)
    scanf("%[^o]s", str2);
    printf("You entered: %s\n", str2);
    fflush(stdin);

    // Never use gets - it is impossible to tell without knowing the data in advance how many characters
    // gets() will read, gets() will continue to store characters past the end of the buffer, it is
    // extremely dangerous to use, use fgets instead.
    /* implementation of gets() function using scanset */
    char str3[128];
    printf("Enter a string with spaces (e.g. hello world): ");
    scanf("%[^\n]s", str3);

    printf("You entered: %s\n", str3);
    fflush(stdin);

    END
}

void gets_usage() {
    char str[4];
    printf("Enter a string (e.g. something): ");
    fgets(str, 4, stdin);
    printf("You entered: %s\n", str); // if you entered 'something', you'll get 'som' instead of 'some'
    assert(str[3] == '\0');
    fflush(stdin);

    END
}

void puts_usage() {
    // puts() moves the cursor to next line.
    printf("Using puts: \n");
    puts("Hello ");
    puts("World");
    printf("Using fputs: \n");
    fputs("Hello ", stdout);
    fputs("World", stdout);

    END
}

void percent_n() {
    int c;
    printf("my name is %n ray!", &c); // equals to the length of "my name is "
    assert(c == 11);

    END
}

void print_percent_char() {
    printf("%%");
    printf("%c", '%');
    printf("%s", "%");

    END
}

void fflush_stdin() {
    // it is not recommended to use it as it is undefined behavior by language standard.
    char str[20];
    int i;
    printf("Enter a string: ");
    for (i = 0; i < 2; i++) {
        scanf("%[^\n]s", str);
        printf("%s\n", str);
    }
    printf("\nEnter a string: ");
    fflush(stdin);
    for (i = 0; i < 2; i++) {
        scanf("%[^\n]s", str);
        printf("%s\n", str);
        fflush(stdin);
    }

    END
}

int main(void) {
    percent_n();
    print_percent_char();
    scanf_usage();
    gets_usage();
    puts_usage();
    fflush_stdin();
    io_basic();

    return 0;
}