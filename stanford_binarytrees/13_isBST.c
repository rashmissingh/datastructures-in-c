#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *insert_node(struct tnode *root, int data);
struct tnode *new_node(int data);
int min_value(struct tnode *pnode);
int print_tree(struct tnode *root);

int main(int argc, int *argv[]) 
{
    struct tnode *pnode = NULL;
	int data = 0, minval = 0;
    
	printf("Enter space separated list of numbers to be inserted\n");

	scanf("%d", &data);
	while (data != -1) {
	    pnode = insert_node(pnode, data);
	    scanf("%d", &data);
	}

	minval = min_value(pnode);

	printf("Tree (min_value) = %d\n", minval);
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

int isBST(struct tnode *root, int *min, int *max) 
{
	int min_left = 0, min_right = 0, max_left = 0, max_right = 0;
	int min = 0, max = 0, flag = -1;

    if (root == NULL) {
	    *min = -1; *max = -1;
		return 0;
    }

    if ((root->left == NULL) && (root->right == NULL)) {
		*min = root->data;
		*max = root->data;
		return 0;
    } 
    else {
	    if (isBST(root->left, &min_left, &max_left) == 1)
		    return 1;

		if ((min_left <= root->data) && (max_left >= root->data)) {
		    *min = min_left;
		}
		else 
		    return 1;

        if (isBST(root->right, &min_right, &max_right) == 1)
            return 1;

		if ((max_right <= root->data) && (max_right >= root->data)) {
		    *max = max_right;
		}
		else 
		    return 1;
	}
    return 0;
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
        if (root->right != NULL)
		    print_tree(root->right);
	}
	printf("%d ", root->data);
	return 0;
}
