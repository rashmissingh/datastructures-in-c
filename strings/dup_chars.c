# Crack Code
# Implement an algorithm to determine if a string has all unique characters. What if
# you can not use additional data structures?

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0, j = 0, count = 0, str_len = 0, dup_found = 0; 
    char *str = NULL;

    if (argc != 2) {
        printf("No string entered\n");
        return 0;
    }
    
    str_len = strlen(argv[1]);
    str = argv[1];
    for (i = 0; i < str_len; i++) {
	    dup_found = 0;
        for (j=i+1; (!dup_found) && (j<str_len); j++) {
	        if (str[i] == str[j]) {
		        dup_found = 1;
	            printf("%c ", str[i]);
		        count++;
	        }
	    }
    }
    if (count)
        printf("- duplicate characters\n");
    else 
        printf("all characters in the string are unique\n");

    return 0;
}




