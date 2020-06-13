#include "strings.h"

void string_usage() {
    char c1[] = "hello";
    char c2[50] = "hello";
    char c3[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char c4[6] = {'h', 'e', 'l', 'l', 'o', '\0'};

    printf("%s\n%s\n%s\n%s", c1, c2, c3, c4);
}

void string_from_stdin() {
    char name[20];
    printf("Enter name: ");
    // "Ray Hong" will saved as "Ray"
    scanf("%s", name);
    printf("Your name is %s.\n", name);

    fflush(stdin);
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    printf("Name: ");
    display_string(name);
}

void string_with_pointers() {
    char greet[] = "Hello World";

    printf("%c ", *greet);
    printf("%c ", *(greet + 1));
    printf("%c ", *(greet + 7));

    printf("\n");
    char *greet_ptr;

    greet_ptr = greet;
    printf("%c ", *greet_ptr);
    printf("%c ", *(greet_ptr + 1));
    printf("%c ", *(greet_ptr + 7));
}

void display_string(char str[]) {
    puts(str);
}