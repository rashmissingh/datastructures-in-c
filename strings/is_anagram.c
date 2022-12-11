#include <stdio.h>

void swap(char *a, char *b);
int bubble_sort(char *str);

int main(int argc, char *argv[])
{
    int len1 = 0, len2 = 0; 
    char *str1 = NULL, *str2 = NULL;

    if (argc != 3) {
        printf("Input 2 strings\n");
        return 0;
    }
    
    str1 = argv[1]; str2 = argv[2];
    len1 = strlen(str1); len2 = strlen(str2);
    if (len1 != len2) {
        printf("strings %s and %s are not anagrams\n", str1, str2);
	return 0;
    }

    bubble_sort(str1);
    bubble_sort(str2);
    if (strcmp(str1, str2) != 0) {
        printf("strings %s and %s are not anagrams\n", argv[1], argv[2]);
        return 0;
    }
    else {
        printf("strings %s and %s are anagrams\n", argv[1], argv[2]);
    }

    return 0;
}

int bubble_sort(char *str)
{
    int i = 0, j =0, sorted = 0;
    int temp, len = strlen(str);

    for(i =0; ((i < len) && (!sorted)); i++) {
	sorted = 1;
        for (j = 0; j < len-i-1; j++) {
	    if (str[j] > str[j+1]) {
	        swap(&str[j], &str[j+1]);
		sorted = 0;
            }
        }
    }

    return 0;
}

void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

