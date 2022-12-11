#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct scores {
    int s[3];
    int score;
} Scores;

void compare(Scores *a, Scores *b);

int main(){
    Scores a, b;
    
    scanf("%d %d %d",&a.s[0],&a.s[1],&a.s[2]);
    scanf("%d %d %d",&b.s[0],&b.s[1],&b.s[2]);
    compare(&a, &b);
    printf("%d %d\n", a.score, b.score);
    return 0;
}

void compare(Scores *a, Scores *b) {
    int i = 0;
    for (i=0; i<3; i++) {
        if (a->s[i] > b->s[i])
            a->score += 1;
        else if (a->s[i] < b->s[i]) {
            b->score += 1;
        }
    }
}


