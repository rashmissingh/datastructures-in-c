#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int lonelyinteger(int a_size, int* a);
int lookup_int(int *numbers, int size, int a);

int main() {
    int res;
    
    int _a_size, _a_i;
    scanf("%d", &_a_size);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        int _a_item;
        scanf("%d", &_a_item);
        
        _a[_a_i] = _a_item;
    }
    
    res = lonelyinteger(_a_size, _a);
    printf("%d", res);
    
    return 0;
}

int lonelyinteger(int a_size, int* a) {
    int i = 0, j = 0, lonelyint = 0, uniq_sz = 0;
    int d_flag = 0, l_flag = 0;
    
    int *uniq_set = (int *) malloc (sizeof(int) * a_size/2);
    
    for (i=0; i<a_size && (!l_flag); i++) {

        if (lookup_int(uniq_set, uniq_sz, a[i]) == 1)
            continue;

        d_flag = 0; 
        for (j=i+1; j<a_size && (!d_flag); j++) {
            if (a[i] == a[j]) {
                d_flag = 1;                
                uniq_set[uniq_sz++] = a[i];
            }
        }
        if (d_flag == 0) {
            lonelyint = a[i];
            l_flag = 1;
        }
    }
    return lonelyint;
}

int lookup_int(int *numbers, int size, int a) {
    int i = 0, found = 0;

    for (i=0; i<size && (!found); i++) {
        if (a == numbers[i])
            found = 1;
    }

    return found;
}



