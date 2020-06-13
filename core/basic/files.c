#include "files.h"

static char tmp_file[100] = "/tmp/c-practice.txt";

/**
 * Opening Modes in Standard I/O
 * Mode	    Meaning of Mode	                                    During Inexistence of file
 * r	    Open for reading.	                                If the file does not exist, fopen() returns NULL.
 * rb	    Open for reading in binary mode.	                If the file does not exist, fopen() returns NULL.
 * w	    Open for writing.	                                If the file exists, its contents are overwritten.
 *                                                              If the file does not exist, it will be created.
 * wb	    Open for writing in binary mode.	                If the file exists, its contents are overwritten.
 *                                                              If the file does not exist, it will be created.
 * a	    Open for append.
 *          Data is added to the end of the file.	            If the file does not exist, it will be created.
 * ab	    Open for append in binary mode.
 *          Data is added to the end of the file.	            If the file does not exist, it will be created.
 * r+	    Open for both reading and writing.	                If the file does not exist, fopen() returns NULL.
 * rb+	    Open for both reading and writing in binary mode.	If the file does not exist, fopen() returns NULL.
 * w+	    Open for both reading and writing.	                If the file exists, its contents are overwritten.
 *                                                              If the file does not exist, it will be created.
 * wb+	    Open for both reading and writing in binary mode.	If the file exists, its contents are overwritten.
 *                                                              If the file does not exist, it will be created.
 * a+	Open for both reading and appending.	                If the file does not exist, it will be created.
 * ab+	Open for both reading and appending in binary mode.	    If the file does not exist, it will be created.
 */

void file_usage() {
    int num;
    FILE *fptr;

    fptr = fopen(tmp_file, "w");

    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    printf("Enter num: ");
    scanf("%d", &num);

    fprintf(fptr, "%d", num);
    fclose(fptr);

    // read file
    if ((fptr = fopen(tmp_file, "r")) == NULL) {
        printf("Error occurred when opening a file.");
        exit(1);
    }
    fscanf(fptr, "%d", &num);
    printf("Value of n=%d", num);
    fclose(fptr);
}
