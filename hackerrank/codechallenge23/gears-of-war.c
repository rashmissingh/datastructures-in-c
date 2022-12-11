#include <stdio.h>

#define T 100000
#define N 100000

int main(int argc, char *argv[])
{
    int i = 0, n = 0, ans = 0, test_count = 0; 

    scanf("%d", &test_count);
	test_count = (test_count > T) ? T : test_count;
    
    for (i = 0; i < test_count; i++) {
        scanf("%d", &n);
        ans = n % 2 ? printf("No\n") : printf("Yes\n");
    }
    return 0;
}

