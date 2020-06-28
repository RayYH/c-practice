#include "variables.h"

/*
 ***********************************************************************************************************************
 *
 * Useful Links:
 *
 * https://www.geeksforgeeks.org/difference-between-definition-and-declaration/
 * https://www.geeksforgeeks.org/understanding-extern-keyword-in-c/
 * https://www.geeksforgeeks.org/static-variables-in-c/
 * https://www.geeksforgeeks.org/what-are-static-functions-in-c/
 * https://www.geeksforgeeks.org/variables-and-keywords-in-c/
 * https://www.geeksforgeeks.org/void-pointer-c-cpp/
 * https://www.geeksforgeeks.org/g-fact-16/
 *
 ***********************************************************************************************************************
 */

int z = 10;

typedef long long int LL;


// Variable Declaration:
//
// type variable_name;
// type variable_1_name, variable_2_name, variable_3_name;
// see data_types() in data_types.c file
void variables_assertion() {
    const int a = 32;
    char b = 'G';
    LL c = 1000000;
    assert(a == 32);
    assert(b == 'G');
    assert(c == 1000000);
    int i = 0;
    while (i++ < 4) {
        static int y = 5;
        y++;
        assert(y == 5 + i);
    }
    assert(z == 10);
}

// const data_type var_name = var_value;
// Constant variables must be initialized during their declaration. const keyword is also used with pointers.
void const_keyword() {
    const int i = 10;
    // i = 11 ->error
    assert(i == 10);

    int j = 20;
    int k = 30;
    const int *p = &j; // or you can use int const*p = &j;
    assert((*p) == 20);
    // we cannot change value by pointer: *p = 100;
    // but we can change p
    p = &k;
    assert((*p) == 30);

    int const *p_i = &i;
    assert((*p_i) == 10);
    /*
     * valid. We call it up qualification. In C/C++, the type of "int *" is allowed to up qualify to the type
     * "const int *". The type of &k is "int *" and is implicitly up qualified by the compiler to "const int *"
     *
     * Note: Down qualification is not allowed in C++ and may cause warnings in C.
     */
    p_i = &k;
    assert((*p_i) == 30);

    const int *const ptr = &i;
    assert((*ptr) == 10);
    // ptr = &j;    -> error
    // *ptr = 100;  -> error
}

void extern_keyword() {
    // global_int was declared in main.c file
    extern int global_int;
    assert(global_int == 1);
    global_int = 10;
    assert(global_int == 10);
    global_int = 1;
    assert(global_int == 1);
}

void void_keyword() {
    // malloc() and calloc() return void * type and this allows these functions to be used to allocate memory of
    // any data type
    int a = 10;
    char b = 'b';

    void *p = &a;
    assert(*(int *) (p) == 10);

    p = &b;
    assert(*(char *) (p) == 'b');

    int c[2] = {1, 2};
    void *ptr = &c;
    ptr = ptr + sizeof(int);
    // Only in GNC C
    assert(*(int *) ptr == 2);
}

static int static_counter() {
    // Static variables are allocated memory in data segment, not stack segment.
    // Static variables (like global variables) are initialized as 0 if not initialized explicitly.
    // In C, static variables can only be initialized using constant literals.
    // Static variables should not be declared inside structure.
    static int count;
    count++;

    return count;
}

static int counter() {
    int count = 0;
    count++;
    return count;
}

void static_keyword() {
    assert(counter() == 1);
    assert(counter() == 1);
    assert(static_counter() == 1);
    assert(static_counter() == 2);
}