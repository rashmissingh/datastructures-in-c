#include <stdio.h>

#define MAXSIZE 100

int read_array(int *r, int *count);
int print_array(int *r, int size);
int surpasser_count(int *a, int *count, int size);
void swap(int *a, int *b);

int main()
{
    int i = 0, position = -1, size = 0; 
    int numbers[MAXSIZE] = {0};
    int surpasser[MAXSIZE] = {0};

    /*read_array(numbers, &size);*/
    while(scanf("%d", &numbers[i++]) != EOF);
    print_array(numbers, size);

    /*surpasser_count(numbers, surpasser, size);*/

    return 0;

}

int surpasser_count(int *array, int *count, int size)
{
    int i = 0, j =0;

    for(i =0; i < size; i++) {
	count[i] = 0;
        for (j = i+1; j < size; j++) {
	    if (array[i] < array[j]) {
		count[i]++;
            }
        }
        print_array(array, size);
        print_array(count, size); printf("\n");
    }

    return 0;
}

int read_array(int *r, int *count)
{
    int temp = 0;
    int i = 0;
    

    scanf("%d", &temp);

    for(; i < MAXSIZE && temp >= 0; i++)
    {
        r[i] = temp;
        scanf("%d", &temp);
    }

    *count = i;

    if (i == MAXSIZE)
        return 1;

    return 0;
}

int print_array(int *r, int size)
{
    int i = 0;

    if (size > MAXSIZE)
        return 1;

    for(i = 0; i < size; i++)
    {
        printf("%d ", r[i]);
    }
    printf("\n");

    return 0;
}


