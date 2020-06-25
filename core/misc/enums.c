#include "enums.h"

// enum 关键字在 C/C++ 中用于定义枚举类型: enum flag{constant_1, constant_2, constant_3, ...}
// 如果不显示声明枚举的值，则枚举的值依次为 0, 1, 2, 3...
// 然后我们可以用 enum flag constant_X 来声明一个枚举中的元素

enum state {
    Working = 1,
    Failed = 0,
    Frozen = 0 // 两个不同的枚举名可以拥有相同的枚举值
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

// 我们不必全部显示声明值，未声明的值为前一个枚举值 + 1，类似于 Go 中的 iota
enum day {
    sunday = 1,
    monday, // 此时 monday = 2
    tuesday = 5,
    wednesday, // 6
    thursday = 10,
    friday,
    saturday
};

// 你可能注意到在 day 里面，我们并未采用大写，这是因为编译器不允许在当前文件的作用域内存在两个同名的枚举值
// 你可以在 main.c 文件中声明一个同样的枚举值，编译器是 OK 的

enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 3
} card; // 可以使用别名

void enum_usage() {
    enum week today;
    today = Saturday;
    assert(today == 6);
    enum state current_state = Working;
    assert(current_state == 1);
    card = club;
    assert(sizeof(card) == sizeof(int));
    // 枚举值可以直接拿来使用
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

/*
 * 枚举和使用宏定义常量的区别
 *
 * 1. 作用域
 * 2. 枚举可以自动赋值
 */