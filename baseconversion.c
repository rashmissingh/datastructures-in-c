#include <stdio.h>
#include <string.h>

char DIGITS[] = "0123456789abcdefghijklmnopqrstuvwxyz";

void reverse_str(char *str);
void convert_base(long num, int from_base, char *str, int to_base);

int main(int argc, char *argv[])
{
    int i = 0, from_base = 0, to_base = 0; 
	long num = 0; 
    char str[100]  = "";

    printf("Enter number and base: ");
	scanf("%ld %d", &num, &from_base);
    printf("Enter target base: ");
	scanf("%d", &to_base);

    convert_base(num, from_base, str, to_base);
    printf("new number = %s\n", str);

    return 0;
}

void convert_base(long num, int from_base, char *str, int to_base) 
{
	int i = 0, remainder = 0;

	if (num == 0) {
	    str[i] = '0';
		i++;
	} else {
        while (num > 0) {
	        remainder = num % to_base;
		    str[i] = DIGITS[remainder];
		    num /= to_base;
		    i++;
	    }
	}
	str[i] = '\0';

	reverse_str(str);
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
}




