#include <stdio.h>
#include <string.h>

void reverse_str(char *str);
void int2str(long num, char *str);

int main(int argc, char *argv[])
{
    int i = 0, remainder = 0; 
	long num = 0; 
    char str[100]  = "", c;

    printf("Enter number: ");
	scanf("%ld", &num);
	printf("Number: %ld\n", num);

    int2str(num, str);
    printf("string = %s\n", str);
	reverse_str(str);

    printf("string = %s\n", str);

    return 0;
}

void int2str(long num, char *str) 
{
	int i = 0, remainder = 0;

	if (num == 0) {
	    str[i] = '0';
		i++;
	} else {
        while (num > 0) {
	        remainder = num % 10;
		    str[i] = '0' + remainder;
		    num /= 10;
		    i++;
	    }
	}
	str[i] = '\0';
}

void reverse_str(char *str)
{

    int i = 0, half = 0, len = strlen(str);
    char c;

    half = len / 2;

    while (i < half) {
        c = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = c;
		i++;
    } 
	printf("inside reverse_str: %s\n", str);
}




