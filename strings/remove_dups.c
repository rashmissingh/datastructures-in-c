#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0, j = 0, k = 0, l = 0, str_len = 0; 
    char *str = NULL;

    if (argc != 2) {
        printf("No string entered\n");
        return 0;
    }
    
    str_len = strlen(argv[1]);
    str = argv[1];
    i = 0; 
    while (str[i] != '\0') {
        j = i+1;
        while (j<str_len) {
            if (str[i] == str[j]) {
                k = j; l = j + 1;
                    while (str[l] != '\0') {
                        str[k++] = str[l++]; 
                    }
                str[k] = '\0';
            } else { 
                j++;
            }
        }
        i++;
    }

    printf("de-duplicated string %s\n", str);

    return 0;
}




