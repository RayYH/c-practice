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