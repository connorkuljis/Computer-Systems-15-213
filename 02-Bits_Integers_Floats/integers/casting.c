#include <stdio.h>
#include <limits.h>
#include <assert.h>

int main() {

    printf("uint half max: %d\n", UINT_MAX / 2);
    printf("signed int max: %d\n", INT_MAX);
    printf("signed int min: %d\n", INT_MIN);

    printf("T-max = (2^w-1) - 1\n");
    printf("T-min = -2^w-1\n");


    /* ***********************************************************************
     * 8 bit integer type EX 1 Byte 
     *
     * Note: int8_t and uint8_t are typedef to char on platforms where 1 byte
     * is 8 bits. On platforms where it is not, appropriate definition will be
     * given. 
     * **********************************************************************/
    printf("int8_t and uint8_t are typedef to char on platforms where 1 byte is "
	    "8 bits. On platforms where it is not, appropriate definition will "
	    "be given.\n\n"); 

    printf("UCHAR_MAX :\t\t%d\n", UCHAR_MAX);
    printf("UCHAR_MIN :\t\t%d\n", 0);
    printf("SCHAR_MAX :\t\t%d\n", SCHAR_MAX);
    printf("SCHAR_MIN :\t\t%d\n", SCHAR_MIN);

    printf("unsigned zero plus neg one equals UMAX");
    char x = 0;
    unsigned char y = -1;

    printf("\t%d\n", x + y);
    printf("sizeof size_t\t\t%lu\n", sizeof(size_t));


    /* ***********************************************************************
     * LOGICAL VS ARITHMETIC SHIFT
     * https://stackoverflow.com/questions/7622/are-the-shift-operators-arithmetic-or-logical-in-c
     *
     * |--------------------------------------------------------------|
     * | Direction  |   Type   | Value (i) | Result                   |
     * | ---------- | -------- | --------- | ------------------------ |
     * | Right (>>) | unsigned |    ≥ 0    | −∞ ← (i ÷ 2ⁿ)            |
     * | Right      | signed   |    ≥ 0    | −∞ ← (i ÷ 2ⁿ)            |
     * | Right      | signed   |    < 0    | Implementation-defined†  |
     * | Left  (<<) | unsigned |    ≥ 0    | (i * 2ⁿ) % (T_MAX + 1)   |
     * | Left       | signed   |    ≥ 0    | (i * 2ⁿ) ‡               |
     * | Left       | signed   |    < 0    | Undefined                |
     * |--------------------------------------------------------------|
     *
     * **********************************************************************/

    signed int x1 = 5;
    assert((x1 >> 1) == 2);

    signed int x2 = -5;
    assert((x2 >> 1) == -3);

    unsigned int x3 = (unsigned int)-5;
    assert((x3 >> 1) == 0x7FFFFFFD);
    printf("uint -5 div 2 (by shifiting), result =\t%d\n", x3 >> 1);
    printf("%d\n", 0x7FFFFFFD);

    return 0;
}

