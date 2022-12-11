#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i = 0, str_len = 0; 
    char str[100]  = "", c;

    if (argc != 2) {
        printf("No string entered\n");
        return 0;
    }
    
    strcpy(str, argv[1]);
    str_len = strlen(argv[1]);
    printf("%s length is %d\n", str, str_len);
    for (i = 0; i < str_len/2; i++) {
        c = str[i];
        str[i] = str[str_len-1-i];
        str[str_len-1-i] = c;
    }
    printf("string = %s, reversed string = %s\n", argv[1], str);

    return 0;
}




