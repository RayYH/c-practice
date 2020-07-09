#include "stdio.h"
#include "assert.h"

// The keyword `enum` is used to declare new enumeration types in C and C++.
// enum flag{constant_1, constant_2, constant_3, ...}

// By default, the values of the constants are as follows: constant_1 = 0, constant_2 = 1, constant_3 = 2 and so on.

// We can declare an enum value: enum flag constant_x, while use constant_x directly is also allowed.

/*
 * Enum vs Macro
 *
 * 1. Enums follow scope rules.
 * 2. Enum variables are automatically assigned values.
 */

enum state {
    Working = 1,
    Failed = 0,
    Frozen = 0 // Two enum names can have same value.
};

enum week {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

// If we do not explicitly assign values to enum names, the compiler by default assigns values from 0.
// We can assign values to some name in any order. All unassigned names get value as value of previous name plus one.
// The value assigned to enum names must be a valid integer, i.e., the value must be in range from minimum possible
// integer value to maximum possible integer value.
enum day {
    sunday = 1,
    monday, // monday = 2
    tuesday = 5,
    wednesday, // 6
    thursday = 10,
    friday,
    saturday
};

// You may noticed that we capitalized the first letter in each word of `week` enums, while the first letter in each
// word of day is lower. This is because all enum constants must be unique in their scope.
// You can define a same enum inside `main.c` file, the compiler will not throw an error, but inside current file,
// same enum name is not allowed!

enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 3
} card; // You can use an alias.

void enum_test() {
    enum week today;
    today = Saturday;
    assert(today == 6);
    enum state current_state = Working;
    assert(current_state == 1);
    card = club;
    assert(sizeof(card) == sizeof(int));
    // we can use enum names directly
    assert(Working == 1);
    assert(Failed == 0);
    assert(Frozen == 0);
    assert(sunday == 1);
    assert(monday == 2);
    assert(tuesday == 5);
    assert(wednesday == 6);
    assert(thursday == 10);
    assert(friday == 11);
    assert(saturday == 12);
    assert(club == 0);
    assert(diamonds == 10);
    assert(hearts == 20);
    assert(spades == 3);
}

void switch_enums() {
    enum week today;
    int i;
    printf("Enter an integer which is greater than 0: ");
    scanf("%d", &i);
    today = i % 7;

    switch (today) {
        case Sunday:
            printf("Sunday!\n");
            break;
        case Monday:
            printf("Monday!\n");
            break;
        case Tuesday:
            printf("Tuesday!\n");
            break;
        case Wednesday:
            printf("Wednesday!\n");
            break;
        case Thursday:
            printf("Thursday!\n");
            break;
        case Friday:
            printf("Friday!\n");
            break;
        case Saturday:
            printf("Saturday!\n");
            break;
        default:
            printf("Invalid!");
            break;
    }
}

int main(void) {

    enum_test();
    switch_enums();

    return 0;
}