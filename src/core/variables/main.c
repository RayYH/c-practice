#include "assert.h"
#include "stdio.h"

/*
 *******************************************************************************
 *
 * Useful Links:
 *
 * https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
 * https://www.geeksforgeeks.org/difference-between-definition-and-declaration/
 * https://www.geeksforgeeks.org/understanding-extern-keyword-in-c/
 * https://www.geeksforgeeks.org/static-variables-in-c/
 * https://www.geeksforgeeks.org/what-are-static-functions-in-c/
 * https://www.geeksforgeeks.org/variables-and-keywords-in-c/
 * https://www.geeksforgeeks.org/void-pointer-c-cpp/
 * https://www.geeksforgeeks.org/g-fact-16/
 *
 *******************************************************************************
 */

// global variable
int z = 10;
// type definition
typedef long long int LL;


// Variable Declaration:
//
// type variable_name;
// type variable_1_name, variable_2_name, variable_3_name;
void variables_assertion() {
    char b = 'G';
    LL c = 1000000;

    assert(b == 'G');
    assert(c == 1000000);

    int i = 0;
    while (i++ < 4) {
        // static variables will hold old values
        static int y = 5;
        y++;
        assert(y == 5 + i);
    }

    assert(z == 10);
}

// const data_type var_name = var_value;
// Constant variables must be initialized during their declaration.
// const keyword is also used with pointers.
void const_keyword() {
    // i is a constant of int type
    const int i = 10;
    // i = 11 -> error
    assert(i == 10);

    int j = 20;
    // p is a pointer to int const (const int)
    const int *p = &j; // or you can use int const *p = &j;
    assert((*p) == 20);
    // we cannot change value by pointer(p of type const *): *p = 100;
    // but we can change p - (since p is not a constant)
    int k = 30;
    p = &k;
    assert((*p) == 30);

    // p_i is a pointer to const int
    int const *p_i = &i;
    assert((*p_i) == 10);
    /*
     * valid. We call it up qualification. In C/C++, the type of "int *" is
     * allowed to up qualify to the type "const int *". The type of &k is
     * "int *" and is implicitly up qualified by the compiler to "const int *"
     *
     * Down qualification is not allowed in C++ and may cause warnings in C.
     */
    p_i = &k; // also, we can change the value of pointer
    assert((*p_i) == 30);

    // p tr is a constant pointer to const int
    const int *const ptr = &i;
    assert((*ptr) == 10);
    // ptr = &j;    -> error
    // *ptr = 100;  -> error
}

void extern_keyword() {
    // global_int was declared at the below
    extern int global_int;
    assert(global_int == 1);
    global_int = 10;
    assert(global_int == 10);
    global_int = 1;
    assert(global_int == 1);
}

void void_keyword() {
    // malloc() and calloc() return void * type and this allows these functions
    // to be used to allocate memory of any data type
    int a = 10;
    char b = 'b';

    void *p = &a;
    assert(*(int *) (p) == 10);

    p = &b;
    assert(*(char *) (p) == 'b');

    int c[2] = {1, 2};
    void *ptr = &c;
    ptr = ptr + sizeof(int);
    // Only in GNU C
    assert(*(int *) ptr == 2);
}

static int static_counter() {
    // Static variables are allocated memory in data segment, not stack segment.
    // Static variables (like global variables) are initialized as 0 if not
    // initialized explicitly.
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

int global_int = 1;

int main(void) {
    assert(global_int == 1);
    variables_assertion();
    const_keyword();
    extern_keyword();
    void_keyword();
    static_keyword();

    return 0;
}