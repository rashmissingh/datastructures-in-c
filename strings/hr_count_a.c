#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long strnchr(char *s, long len, char a);

int main(){
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s",s);
    long n, len = 0, count = 0, count1 = 0, count2 = 0; 
    long quotient = 0, remainder = 0; 

    scanf("%ld",&n);

    len = strlen(s);
    quotient = n / len;
    remainder = n % len;

    count1 = strnchr(s, len, 'a');
    count2 = strnchr(s, remainder, 'a');
    count = ((count1*quotient) + count2);

	printf("%ld", count);

    return count;
}

long strnchr(char *s, long len, char a)
{
    long count = 0;
    for (int i = 0; i<len; i++) {
        if (s[i] == a)
            count++;
    }
    return count;
}
