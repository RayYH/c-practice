#include "pointers.h"

void pointers_usage() {
    int var = 5;
    int *p;
    p = &var;
    // or
    int *q = &var;

    printf("address: %p\n", &var);
    printf("address: %p\n", p);
    printf("address: %p\n", q);

    // access variables

    printf("value: %d\n", var);
    printf("value: %d\n", *p);
    printf("value: %d\n", *q);

    // change value
    var = 10;

    printf("new value: %d\n", var);
    printf("new value: %d\n", *p);
    printf("new value: %d\n", *q);
}

void pointers_with_arrays() {
    int x[4];
    int i;

    for (i = 0; i < 4; i++) {
        printf("&x[%d] = %p\n", i, &x[i]);
    }

    printf("Address of array x: %p\n", x);

    int y[5] = {1, 2, 3, 4, 5};
    int *ptr;

    // ptr is assigned the address of the third element
    ptr = &y[2];

    printf("*ptr = %d \n", *ptr);   // 3
    printf("*(ptr+1) = %d \n", *(ptr + 1)); // 4
    printf("*(ptr-1) = %d", *(ptr - 1));  // 2
}

void memory_usage() {
    int *ptr = (int *) malloc(10 * sizeof(int));

    if (ptr == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    for (int i = 0; i < 10; i++) {
        *(ptr + i) = rand() % 100;
    }


    for (int i = 0; i < 10; i++) {
        printf("%4d ", *(ptr + i));
    }

    printf("\n");

    ptr = realloc(ptr, 20 * sizeof(int));

    if (ptr == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    for (int i = 0; i < 20; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }
        printf("%4d ", *(ptr + i));
    }

    printf("\n");

    ptr = (int *) calloc(20, sizeof(int));

    if (ptr == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    for (int i = 0; i < 20; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }
        printf("%4d ", *(ptr + i));
    }

    free(ptr);
}

void pointer_trick() {
    printf("111");
    int doses[] = {1, 3, 2, 1000};
    // doses[3] == *(doses + 3) == *(3 + doses) == 3[doses]
    //assert(3[doses] == 1000);

    // string literal cannot be changed
//    char *cards = "JQK";
//    char cards2[] = "JQK";
//    char a_card = cards[2];
//    cards[2] = cards[1];
//    cards[1] = cards[0];
//    cards[0] = cards[2];
//    cards[2] = cards[1];
//    cards[1] = a_card;
//    assert(strcmp(cards, "JQK") == 0);
//    a_card = cards2[2];
//    cards2[2] = cards2[1];
//    cards2[1] = cards2[0];
//    cards2[0] = cards2[2];
//    cards2[2] = cards2[1];
//    cards2[1] = a_card;
//    printf("%s", cards2);
//    assert(strcmp(cards2, "JQK") == 0);
}