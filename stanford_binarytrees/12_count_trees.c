#include<stdio.h>

int main() 
{
    int numKeys = 0;

	printf("Enter number of keys: ");
	scanf("%d", &numKeys);

	nTrees = count(numKeys);

	printf("Number of structurally different BST: %d\n", nTrees);
}

int count_trees(int n) 
{
    if (n <= 1) {
	    return 1;
    } else {
	    nLeft = count_trees(n-1);
		nRight = count 
}

