#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *insert_node(struct tnode *root, int data);
struct tnode *new_node(int data);
int print_tree(struct tnode *root);
int mirror_tree(struct tnode *root);
void swap_nodes(struct tnode **left, struct tnode **right);

int main(int argc, int *argv[]) 
{
    struct tnode *pnode = NULL;
	int data = 0;
    
	printf("Enter space separated list of numbers to be inserted\n");

	scanf("%d", &data);
	while (data != -1) {
	    pnode = insert_node(pnode, data);
	    scanf("%d", &data);
	}

	printf("Original tree: ");
	print_tree(pnode);
	printf("\n");

	mirror_tree(pnode);

	printf("Mirrored tree: ");
	print_tree(pnode);
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

int mirror_tree(struct tnode *root) 
{
    if ((root->left == NULL) && (root->right == NULL)) {
		return 0;
    }
    else {
	    if (root->left != NULL)
		    mirror_tree(root->left);

        if (root->right != NULL)
		    mirror_tree(root->right);

	    swap_nodes(&(root->left), &(root->right));
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

	    printf("%d ", root->data);

        if (root->right != NULL)
		    print_tree(root->right);
	}
	return 0;
}

void swap_nodes(struct tnode **left, struct tnode **right)
{
    struct tnode *tptr = NULL;

	tptr = *left;
	*left = *right;
	*right = tptr;

	return;
}



