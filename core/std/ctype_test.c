#include "ctype_test.h"

// links:
// http://www.cplusplus.com/reference/cctype
// https://www.programiz.com/c-programming/library-function/ctype.h/isgraph

void isalnum_test() {
    char str[] = "c3po...";
    int i = 0;
    // first 4 characters are alphanumeric, so the i is 5
    while (isalnum(str[i++]));
    assert(i == 5);
}

void isalpha_test() {
    int i = 0;
    char str[] = "C++";
    while (str[i]) {
        if (isalpha(str[i])) {
            assert(str[i] == 'C');
        } else {
            assert(str[i] == '+');
        }
        i++;
    }
}

void isblank_test() {
    char c;
    int i = 0;
    char str[] = "Example sentence to test isblank\n";
    char new_str[strlen(str)];
    while (str[i]) {
        c = str[i];
        if (isblank(c)) {
            c = '\n';
        }
        new_str[i++] = c;
    }
    assert(strcmp(new_str, "Example\nsentence\nto\ntest\nisblank\n") == 0);
}

void iscntrl_test() {
    int i = 0;
    char str[] = "first line \n second line \n";
    char new_str[strlen(str)];
    while (!iscntrl(str[i])) {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    assert(strcmp(new_str, "first line ") == 0);
}

void isdigit_test() {
    int year;
    char str[] = "1776ad";
    if (isdigit(str[0])) {
        year = atoi(str);
        assert(year == 1776);
    }
}

// The characters with graphical representation are all those characters
// than can be printed (as determined by isprint) except the space character (' ').
void isgraph_test() {
    int i;
    printf("\n\n");
    printf("All graphic characters in C programming are: \n");
    for (i = 0; i <= 127; ++i) {
        if (isgraph(i) != 0) {
            printf("%c ", i);
        }
    }
    printf("\n\n");
}

void islower_test() {
    int i = 0;
    char str[] = "Test String.";
    char new_str[strlen(str)];
    char c;
    while (str[i]) {
        c = str[i];
        if (islower(c)) {
            c = toupper(c);
        }
        new_str[i++] = c;
    }

    assert(strcmp(new_str, "TEST STRING.") == 0);
}

// A printable character is a character that occupies a printing position on a display
// (this is the opposite of a control character, checked with iscntrl).
void isprint_test() {
    int i = 0;
    char str[] = "first line \n second line \n";
    while (isprint(str[i++]));
    assert(i == 12);
}

// The standard "C" locale considers punctuation characters all graphic characters (as in isgraph)
// that are not alphanumeric (as in isalnum).
void ispunct_test() {
    int i = 0;
    int cx = 0;
    // , and ! arr punctuations.
    char str[] = "Hello, welcome!";
    while (str[i]) {
        if (ispunct(str[i])) {
            cx++;
        }
        i++;
    }
    assert(cx == 2);
}

// For the "C" locale, white-space characters are any of:
// ' '	(0x20)	space (SPC)
// '\t'	(0x09)	horizontal tab (TAB)
// '\n'	(0x0a)	newline (LF)
// '\v'	(0x0b)	vertical tab (VT)
// '\f'	(0x0c)	feed (FF)
// '\r'	(0x0d)	carriage return (CR)
void isspace_test() {
    char c;
    int i = 0;
    char str[] = "Example\tsentence\vto\rtest isspace\n";
    char new_str[strlen(str)];
    while (str[i]) {
        c = str[i];
        if (isspace(c)) {
            c = '\n';
        }
        new_str[i++] = c;
    }
    assert(strcmp(new_str, "Example\nsentence\nto\ntest\nisspace\n") == 0);
}

void isupper_test() {
    int i = 0;
    char str[] = "Test String.";
    char new_str[strlen(str)];
    char c;
    while (str[i]) {
        c = str[i];
        if (isupper(c)) {
            c = tolower(c);
        }
        new_str[i++] = c;
    }

    assert(strcmp(new_str, "test string.") == 0);
}

// Hexadecimal digits are any of: 0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F
void isxdigit_test() {
    char str[] = "fab";
    long int number;
    if (isxdigit(str[0])) {
        number = strtol(str, NULL, 16);
        assert(number == 4011);
    }
}

void all_characters() {
    printf("Displaying all ascii characters: \n\n");
    printf("%12s%12s%12s%12s%12s%12s%12s%12s%12s%12s%12s%12s%12s%12s\n",
           "ASCII value", "character", "iscntrl", "isblank", "isspace", "isupper",
           "islower", "isalpha", "isdigit", "isxdigit", "isalnum", "ispunct", "isgraph", "isprint"
    );
    char iscntrl_ch, isblank_ch, isspace_ch, isupper_ch, islower_ch, isalpha_ch,
            isdigit_ch, isxdigit_ch, isalnum_ch, ispunct_ch, isgraph_ch, isprint_ch;
    char ch;
    for (int i = 0; i < 128; i++) {
        ch = (char) i;
        iscntrl_ch = iscntrl(ch) ? 'Y' : 'N';
        isblank_ch = isblank(ch) ? 'Y' : 'N';
        isspace_ch = isspace(ch) ? 'Y' : 'N';
        isupper_ch = isupper(ch) ? 'Y' : 'N';
        islower_ch = islower(ch) ? 'Y' : 'N';
        isalpha_ch = isalpha(ch) ? 'Y' : 'N';
        isdigit_ch = isdigit(ch) ? 'Y' : 'N';
        isxdigit_ch = isxdigit(ch) ? 'Y' : 'N';
        isalnum_ch = isalnum(ch) ? 'Y' : 'N';
        ispunct_ch = ispunct(ch) ? 'Y' : 'N';
        isgraph_ch = isgraph(ch) ? 'Y' : 'N';
        isprint_ch = isprint(ch) ? 'Y' : 'N';
        printf("%12x", i);
        if (i >= '!' && i <= '~') {
            printf("%12c", i);
        } else {
            printf("%12c", 0x20);
        }

        printf("%12c%12c%12c%12c%12c%12c%12c%12c%12c%12c%12c%12c\n",
               iscntrl_ch, isblank_ch, isspace_ch, isupper_ch, islower_ch, isalpha_ch,
               isdigit_ch, isxdigit_ch, isalnum_ch, ispunct_ch, isgraph_ch, isprint_ch
        );
    }

    printf("\n\n");
}