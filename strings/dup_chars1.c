/* Crack Code
# Implement an algorithm to determine if a string has all unique characters. What if
# you can not use additional data structures?
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0, posn = 0, str_len = 0, dup_found = 0; 
    int status[26] = {0};
    char *str = NULL;

    if (argc != 2) {
        printf("No string entered\n");
        return 0;
    }
    
    str_len = strlen(argv[1]);
    str = argv[1];
    for (i = 0; (!dup_found) && (i < str_len); i++) {
	    posn = str[i] - 'a'; printf("posn = %d, char = %c\n", posn, str[i]);
        if (status[posn]) 
	        dup_found = 1;
        else 
	        status[posn] = 1;
    }
    if (dup_found)
        printf("%c - is duplicate character\n", str[i-1]);
    else 
        printf("all characters in the string are unique\n");

    return 0;
}




