#include<stdio.h>
#include<stdlib.h>

struct tnode {
    int data;
	struct tnode *left;
	struct tnode *right;
};

void build_tree(struct tnode **root);
void insert_node(struct tnode **root, int data);
struct tnode *new_node(int data);
void print_tree(struct tnode *root);

void main() 
{
    struct tnode *tree = NULL;

	build_tree(&tree);
	print_tree(tree);
	printf("\n");
}

void build_tree(struct tnode **root)
{
	int data = 0;

	printf("Enter tree elements terminated by -1\n");
	scanf("%d", &data);
	while (data != -1) {
	    insert_node(root, data);
		scanf("%d", &data);
	}
}

void insert_node(struct tnode **root, int data) {
    if (*root == NULL) {
	    *root = new_node(data);
		return;
    } else {
	    if ((*root)->data >= data)
		    insert_node(&(*root)->left, data);
        if ((*root)->data < data)
		    insert_node(&(*root)->right, data);
	}
}

struct tnode *new_node(int data)
{
    struct tnode *newnode = (struct tnode *)malloc (sizeof(struct tnode));

	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
}

void print_tree(struct tnode *root)
{
    if ((root->left == NULL) && (root->right == NULL)) {
	    printf("%d ", root->data);
    } else {
	    if (root->left != NULL)
		    print_tree(root->left);

		if (root->right != NULL)
		    print_tree(root->right);

        printf("%d ", root->data);
    }
	return;
}



