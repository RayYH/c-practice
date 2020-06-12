#include "keywords.h"

/**
 * 1. A valid identifier can have letters (both uppercase and lowercase letters), digits and underscores.
 * 2. The first letter of an identifier should be either a letter or an underscore.
 * 3. You cannot use keywords as identifiers.
 */

/**
 * Escape Sequences	Character
 *
 * \b	Backspace
 * \f	Form feed
 * \n	Newline
 * \r	Return
 * \t	Horizontal tab
 * \v	Vertical tab
 * \\	Backslash
 * \'	Single quotation mark
 * \"	Double quotation mark
 * \?	Question mark
 * \0	Null character
 */

void print_section(int first, int second) {

    if (first > second) {
        return;
    }

    for (int i = first; i < second; i++) {
        printf("%c ", i);
    }
}

void print_character_set() {
    print_section('A', 'Z');
    print_section('a', 'z');
    print_section('0', '9');
}

void print_special_characters() {
    char chs[29] = {
            ',', '<', '>', '.', '_', '(', ')', ';', '$', ':', '%', '[', ']', '#', '?', '\'', '&', '{', '}', '"', '^',
            '!', '*', '/', '|', '-', '\\', '~', '+',
    };
    int size = sizeof(chs) / sizeof(char);
    for (int i = 0; i < size; i++) {
        printf("%c ", chs[i]);
    }
}

void print_c_keywords() {
    char *chs[32] = {
            "auto", "double", "int", "struct",
            "break", "else", "long", "switch",
            "case", "enum", "register", "typedef",
            "char", "extern", "return", "union",
            "continue", "for", "signed", "void",
            "do", "if", "static", "while",
            "default", "goto", "sizeof", "volatile",
            "const", "float", "short", "unsigned",
    };

    for (int i = 0; i < 32; i++) {
        if (i % 4 == 0) {
            printf("\n");
        }
        printf("%-12s ", chs[i]);
    }
}