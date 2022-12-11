/* Crack Code
# Write a method to replace all spaces in a string with ‘%20’.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0, j = 0, str_len = 0, new_len = 0, space_count = 0; 
    char *str = NULL, *newstr = NULL;

    if (argc != 2) {
        printf("No string entered\n");
        return 0;
    }
    
    str_len = strlen(argv[1]);
    str = argv[1];
    for (i = 0; (i < str_len); i++) {
	    if (str[i] == ' ') space_count++;
    }
    new_len = str_len + space_count * 2;
    newstr = (char *)malloc(sizeof(char) * new_len);
    
	newstr[new_len] = '\0';
    i = str_len -1; j = new_len - 1; 
    while ((i > 0) && (j > 0)) {
        if (str[i] != '\0') {
            newstr[j--] = str[i--];
		}
        else {
            newstr[j] = 0;
			newstr[j-1] = 2;
			newstr[j-2] = '%';
            j-=3; i--;
	    }
    }
	printf("new string %s\n", newstr);
	if (newstr)
	    free(newstr);
    return 0;
}




