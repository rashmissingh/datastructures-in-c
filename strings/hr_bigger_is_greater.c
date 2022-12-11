/*
   Given a word, rearrange the letters of  to construct another word  in
   such a way that  is lexicographically greater than. In case of multiple
   possible answers, find the lexicographically smallest one among them.

Input Format

   The first line of input contains, the number of test cases. Each of the
   next lines contains.

Constraints

   w will contain only lower-case English letters and its length will not
   exceed.

Output Format

   For each testcase, output a string lexicographically bigger than in a
   separate line. In case of multiple possible answers, print the
   lexicographically smallest one, and if no answer exists, print no
   answer.
 */

#include <stdio.h>
#include <string.h>

#define N 100
#define T 100

void next_word(char *str, char *newstr);
int bubble_sort(char *str);
void swap(char *a, char *b);

int main(int argc, char *argv[])
{
    int len = 0, test_count = 0; 
    char str[N], newstr[N] = {0};

    scanf("%d", &test_count); 

	while (test_count > 0) {
        scanf("%s", str); 
        next_word(str, newstr);
        printf("%s\n", newstr);
		test_count--;
	}

    return 0;
}

void next_word(char *str, char *newstr)
{

    int i = 0, posn = 0, len = 0;
    char c;

	if (str == NULL) {
	   strcpy(newstr, "no answer");
	   return;
    }
	   
    len = strlen(str);
    i = len - 1; 
    while (i > 0) {
        if (str[i] <= str[i-1])
		    i--;
        else
		    break;
    } 
	if (i == 0)
	   strcpy(newstr, "no answer");
    else {
	    posn = i-1; i = len-1;
	    while (i > posn) {
		    if (str[i] > str[posn]) {
                swap(&str[posn], &str[i]);
				break;
            }
			i--;
		}
		strcpy(newstr, str);
        if (posn == 0)
            bubble_sort(&newstr[1]);
	}
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




