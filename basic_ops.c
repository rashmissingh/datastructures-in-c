#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int bool, quotient = 0, remainder = 0, dividend = 0, divisor = 0;
    int num = 0;

    if (argc != 3) {
        printf("No arguments entered.  Enter dividend and divisor.\n");
        return 0;
    }

    dividend = atoi(argv[1]);
    divisor = atoi(argv[2]);

    bool = !dividend;
    printf("bool = %d\n", bool);

    quotient = dividend / divisor;
    remainder = dividend % divisor;
    num = dividend;
    num = num / divisor;
    
    printf("%d / %d = %d\n", dividend, divisor, quotient);
    printf("%d %% %d = %d\n", dividend, divisor, remainder);
    printf("num = %d\n", num);

    int i, size = 10, incr = 2;
    for (i = 0; i < size; i+=incr) {
        printf("i = %d, size = %d, incr = %d\n", i, size, incr);
    }

    return 0;
}




