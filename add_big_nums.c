#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void read_array(int *arr, int n);

int main(){
    int n, overflow = 0; 
    long long sum = 0;

    scanf("%d",&n);
    int arr[n];

    read_array(arr, n);

    sum = arr[0];
    for (int i = 1; (!overflow) && (i < n); i++) {
        if ((arr[i] > 0) && (sum < INT_MAX - arr[i]))
            sum += arr[i];
        else 
            overflow = 1;
    }

    if (!overflow)
        printf("%lld\n", sum);
    else
        printf("Error\n");

    return 0;
}

void read_array(int *arr, int n) 
{
    for(int i = 0; i < n; i++){
       scanf("%d",&arr[i]);
    }
}
