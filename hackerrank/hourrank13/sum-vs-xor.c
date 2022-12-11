#include <stdio.h>

#define N 1000000000000000

int main(int argc, char *argv[])
{
    int count = -1; 
	long n = 0;

    scanf("%ld", &n);
	if (n > N) {
	    count = -1;
	} else {
        count = 0;
	    for (long i = 0; i<=n; i++) {
            if ((n + i) == (n ^ i))
		        count++;
	    }
	}
    printf("%d\n", count);
    return 0;
}

