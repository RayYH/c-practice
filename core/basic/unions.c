#include "unions.h"

union union_animal {
    char name[30];
    short age;
} u_animal;

struct struct_animal {
    char name[30];
    short age;
} s_animal;

void union_usage() {
    // the size of a union variable will always be the size of its largest element.
    printf("size of union = %lu bytes\n", sizeof(u_animal));
    printf("size of structure = %lu bytes\n", sizeof(s_animal));

    strcpy(u_animal.name, "Dog");
    u_animal.age = 4;

    printf("%s's age is %d\n", u_animal.name, u_animal.age);
}