#include "enums.h"

enum week {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 3
} card;

void enum_usage() {
    enum week today;
    today = Saturday;
    printf("Day: %d\n", today);

    card = club;
    printf("Size of enum variable = %lu bytes", sizeof(card));
}

void switch_enums() {
    enum week today;
    int i;
    printf("Enter an integer: ");
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