#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int break_number = 0, cont_number = 0;

    if (argc != 3) {
        printf("No arguments entered.  Enter continue and break numbers.\n");
        return 0;
    }

    cont_number = atoi(argv[1]);
    break_number = atoi(argv[2]);

    int i = 0, j = 0;
    printf("break_number=%d, cont_number=%d, i=%d, j=%d\n", break_number, cont_number, i, j);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (j == cont_number)
                continue;
            if (j == break_number)
                break;
            printf("At end of inner for- i=%d, j=%d\n", i, j);
        }
        printf("At end of outer for- i=%d, j=%d\n", i, j);
    }

    return 0;
}




