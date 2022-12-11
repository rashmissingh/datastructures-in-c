/*
   Find a maximum-length contiguous substring of a given string that is 
   also a palindrome.
 */

#include <stdio.h>
#include <string.h>

#define Q 10
#define N 3000
#define K 50

void get_longest_palindrome(char *str, char *palindrome);
int get_max_posn(int *a, unsigned int size);
void extract_palindrome(char *str, char *palindrome, int posn, int len);
int print_array(int *r, int size);

int main(int argc, char *argv[])
{
    int len = 0, test_count = 0, n = 0, k = 0; 
    char str[N], palindrome[N], newstr[N+1], newpalin[N+1];

    scanf("%d", &test_count); 

    test_count = (test_count > Q) ? Q : test_count;

    while (test_count > 0) {
        scanf("%d%d", &n, &k);
        n = (n > N) ? N : n;
        k = (k > N) ? N : k;

        scanf("%s", str); 
        len = strlen(str);
        get_longest_palindrome(str, palindrome);

        count = 0;
        for(i=0; i<26; i++) {
            char c = 'a' + i;
            for (int j=0; j<=len; j++) {
                newstr = {0};
                newstr[j] = c;
                strncpy(newstr, str, j);
                strncpy(&newstr[j+1], str[j+1], len-j);

                get_longest_palindrome(newstr, newpalin);

                if (len = strlen(newpalin) + k;
                    count++
            }
        }

        printf("%s\n", palindrome);
        test_count--;
    }

    return 0;
}

void get_longest_palindrome(char *str, char *palindrome)
{

    int i = 0, len = 0, plen = 0, done = 0, left, right, pomax, pemax;
    int odd_palindrome[N] = {0};
    int even_palindrome[N] = {0};

    if (str == NULL) {
       strcpy(palindrome, "no answer");
       return;
    }
       
    len = strlen(str);
    odd_palindrome[0] = 1;
    even_palindrome[0] = (str[0] == str[1]) ? 2 : 0;

    for (i=1; i<len-1; i++) {
        /* find odd-len palindrome centered around str[i] */
        if ((i-1 >= 0) && (i+1 <= len-1)) {
            plen=1; done = 0;
            for(left=i-1, right=i+1; 
               (((left>=0) && (right<=len-1)) && (!done)); 
               left--, right++) {

                if(str[left] == str[right]) 
                    plen+=2;
                else
                    done=1;
            }
            odd_palindrome[i] = plen;
        }
        /* find even-len palindrome centered around str[i] */
        if (i+1 <= len-1) {
            plen=0; done = 0;
            for(left=i, right=i+1; 
               (((left>=0) && (right<=len-1)) && (!done)); 
               left--, right++) {

                if(str[left] == str[right]) 
                    plen+=2;
                else
                    done=1;
            }
            even_palindrome[i] = plen;
        }
    } 
    
    print_array(odd_palindrome, len);
    print_array(even_palindrome, len);
    pomax = get_max_posn(odd_palindrome, (unsigned int)len);
    pemax = get_max_posn(even_palindrome, (unsigned int)len);
    if (odd_palindrome[pomax] > even_palindrome[pemax])
        extract_palindrome(str, palindrome, pomax, odd_palindrome[pomax]);
    else 
        extract_palindrome(str, palindrome, pemax, even_palindrome[pemax]);

    return;
}

int get_max_posn(int *a, unsigned int size)
{
    int pmax = 0;

    if (size == 0) 
        return -1;

    for (int i = 1; i<size; i++) {
        if (a[pmax] < a[i])
            pmax = i;
    }

    return pmax;
}

void extract_palindrome(char *str, char *palindrome, int posn, int len)
{
    int lbound, rbound;

    lbound = (len%2 == 0) ? posn - ((len / 2) - 1) : posn - (len / 2);
    rbound = posn + (len / 2);

    /*strncpy(palindrome, (const char *)&str[lbound], rbound-lbound+1);*/
    strncpy(palindrome, (const char *)&str[lbound], len);
    palindrome[len] = '\0';

    return;
}

int print_array(int *r, int size)
{
    int i = 0;

    if (size > N)
        return 1;

    for(i = 0; i < size; i++)
    {
        printf("%d ", r[i]);
    }
    printf("\n");

    return 0;
}







