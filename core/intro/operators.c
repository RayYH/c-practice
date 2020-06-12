#include "operators.h"

// https://www.programiz.com/c-programming/c-operators

void arithmetic_operators() {
    int a = 9, b = 4, c;
    c = a + b;
    printf("a+b = %d \n", c);
    c = a - b;
    printf("a-b = %d \n", c);
    c = a * b;
    printf("a*b = %d \n", c);
    c = a / b;
    printf("a/b = %d \n", c);
    c = a % b;
    printf("Remainder when a divided by b = %d \n", c);
}

void increment_decrement_operators() {
    int a = 10, b = 100;
    float c = 10.5f, d = 100.5f;

    printf("++a = %d \n", ++a);
    printf("--b = %d \n", --b);
    printf("++c = %f \n", ++c);
    printf("--d = %f \n", --d);
}

void assignment_operators() {
    int a = 5, c;

    c = a;      // c is 5
    printf("c = %d\n", c);
    c += a;     // c is 10
    printf("c = %d\n", c);
    c -= a;     // c is 5
    printf("c = %d\n", c);
    c *= a;     // c is 25
    printf("c = %d\n", c);
    c /= a;     // c is 5
    printf("c = %d\n", c);
    c %= a;     // c = 0
    printf("c = %d\n", c);
}

void relational_operators() {
    int a = 5, b = 5, c = 10;

    printf("%d == %d is %d \n", a, b, a == b);
    printf("%d == %d is %d \n", a, c, a == c);
    printf("%d > %d is %d \n", a, b, a > b);
    printf("%d > %d is %d \n", a, c, a > c);
    printf("%d < %d is %d \n", a, b, a < b);
    printf("%d < %d is %d \n", a, c, a < c);
    printf("%d != %d is %d \n", a, b, a != b);
    printf("%d != %d is %d \n", a, c, a != c);
    printf("%d >= %d is %d \n", a, b, a >= b);
    printf("%d >= %d is %d \n", a, c, a >= c);
    printf("%d <= %d is %d \n", a, b, a <= b);
    printf("%d <= %d is %d \n", a, c, a <= c);
}

void logical_operators() {
    int c = 10, result;
    int a = c / 2;
    int b = c / 2;

    result = (a == b) && (c > b);
    printf("(a == b) && (c > b) is %d \n", result);
    result = (a == b) && (c < b);
    printf("(a == b) && (c < b) is %d \n", result);
    result = (a == b) || (c < b);
    printf("(a == b) || (c < b) is %d \n", result);
    result = (a != b) || (c < b);
    printf("(a != b) || (c < b) is %d \n", result);
    printf("!((a != b) || (c < b)) is %d \n", !result);
}

void bitwise_operators() {
    /**
     * 12 = 00001100 (In Binary)
     * 25 = 00011001 (In Binary)
     *
     * Bit Operation of 12 and 25
     *   00001100
     * & 00011001
     *   ________
     *   00001000  = 8 (In decimal)
     */

    unsigned int a = 12, b = 25;
    printf("12 & 25 = %d\n", a & b);

    /**
     * 12 = 00001100 (In Binary)
     * 25 = 00011001 (In Binary)
     *
     * Bitwise OR Operation of 12 and 25
     *   00001100
     * | 00011001
     *   ________
     *   00011101  = 29 (In decimal)
     */
    printf("12 | 25 = %d\n", a | b);

    /**
     * 12 = 00001100 (In Binary)
     * 25 = 00011001 (In Binary)
     *
     * Bitwise XOR Operation of 12 and 25
     *   00001100
     * ^ 00011001
     *   ________
     *   00010101  = 21 (In decimal)
     */
    printf("12 ^ 25 = %d\n", a ^ b);

    /**
     * Two's complement is an operation on binary numbers.
     * The 2's complement of a number is equal to the complement of that number plus 1.
     *
     * Decimal         Binary           2's complement
     *   0            00000000           -(11111111+1) = -00000000 = -0(decimal)
     *   1            00000001           -(11111110+1) = -11111111 = -256(decimal)
     *   12           00001100           -(11110011+1) = -11110100 = -244(decimal)
     *   220          11011100           -(00100011+1) = -00100100 = -36(decimal)
     *
     * Note: Overflow is ignored while computing 2's complement.
     *
     * bitwise complement of N = ~N (represented in 2's complement form)
     * 2'complement of ~N= -(~(~N)+1) = -(N+1)
     */

    printf("~12 = %d\n", ~a);
    printf("~-25 = %d\n", ~-b);

    /**
     * Right Shift Operator
     *
     * 212 = 11010100 (In binary)
     * 212>>2 = 00110101 (In binary) [Right shift by two bits]
     * 212>>7 = 00000001 (In binary)
     * 212>>8 = 00000000
     * 212>>0 = 11010100 (No Shift)
     *
     * Left Shift Operator
     * 212 = 11010100 (In binary)
     * 212<<1 = 110101000 (In binary) [Left shift by one bit]
     * 212<<0 =11010100 (Shift by 0)
     * 212<<4 = 110101000000 (In binary) =3392(In decimal)
     */

    unsigned int num = 212, i;
    for (i = 0; i <= 2; ++i) {
        printf("212 right shift by %d: %d\n", i, num >> i);
    }

    for (i = 0; i <= 2; ++i) {
        printf("212 left shift by %d: %d\n", i, num << i);
    }
}