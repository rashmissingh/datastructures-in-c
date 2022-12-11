#include <stdio.h>
#include <stdlib.h>
#include "ll_defs.h"

struct tnode {
    int data;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *insert_node(struct tnode *root, int data);
struct tnode *new_node(int data);
void print_paths(struct tnode *root, int *path, int level);
int print_tree(struct tnode *root);
void print_array(int *arr, int start, int end);

int main(int argc, int *argv[]) 
{
    struct tnode *pnode = NULL;
	int data = 0, level = 0;
	int path[100];
    
	printf("Enter space separated list of numbers to be inserted\n");

	scanf("%d", &data);
	while (data != -1) {
	    pnode = insert_node(pnode, data);
	    scanf("%d", &data);
	}

    print_paths(pnode, path, level);

	/*print_tree(pnode);*/

	printf("\n");
}

struct tnode *insert_node(struct tnode *root, int data) 
{
    if (root == NULL) {
	    root = new_node(data);
		return root;
    }

	if (root->data >= data) {
	    root->left = insert_node(root->left, data);
	} else {
	    root->right = insert_node(root->right, data);
	}
    return root;
}

struct tnode *new_node(int data)
{

    struct tnode *pnode = (struct tnode *) malloc (sizeof(struct tnode));

	pnode->data = data;
	pnode->left = NULL;
	pnode->right = NULL;
	return pnode;
}

int print_tree(struct tnode *root)
{
    if ((root->left == NULL) && (root->right == NULL)) {
        printf("%d ", root->data);
        return 0;
    }
    else {
        if (root->left != NULL)
            print_tree(root->left);

        printf("%d ", root->data);

        if (root->right != NULL)
            print_tree(root->right);
    }
    return 0;
}

void print_paths(struct tnode *root, int *path, int level) 
{
	if (root == NULL)
	    return;

	path[level] = root->data;

	if ((root->left == NULL) && (root->right == NULL))
	    print_array(path, 0, level);

    print_paths(root->left, path, level+1);

    print_paths(root->right, path, level+1);
	
	return;
}

void print_array(int *arr, int start, int end)
{
    int i = 0;

	for (i=start; i<=end; i++) {
	    printf("%d ", arr[i]);
	}
    printf("\n");
}






