#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *insert_node(struct tnode *root, int data);
struct tnode *new_node(int data);
int is_same_tree(struct tnode *tree1, struct tnode *tree2);
int print_tree(struct tnode *root);

int main(int argc, int *argv[]) 
{
    struct tnode *tree1 = NULL, *tree2 = NULL;
	int data = 0, flag = 1;
    
	printf("Enter space separated list of numbers for tree 1\n");
	scanf("%d", &data);
	while (data != -1) {
	    tree1 = insert_node(tree1, data);
	    scanf("%d", &data);
	}

	printf("Enter space separated list of numbers for tree 2\n");
	scanf("%d", &data);
	while (data != -1) {
	    tree2 = insert_node(tree2, data);
	    scanf("%d", &data);
	}

	flag = is_same_tree(tree1, tree2);

    if (flag == 0) printf("Same tree\n");
    else printf("Different tree\n");

	print_tree(tree1);
	printf("\n");
	print_tree(tree2);
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

int is_same_tree(struct tnode *tree1, struct tnode *tree2) 
{
	int flag = 1;

    if ((tree1 == NULL) && (tree2 == NULL)) {
		return 0;
    }
    else {
		if (tree1->data == tree2->data) {
	        if (is_same_tree(tree1->left, tree2->left) == 1)
			    return 1;
	        if (is_same_tree(tree1->right, tree2->right) == 1)
			    return 1;
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

	    printf("%d ", root->data);

        if (root->right != NULL)
		    print_tree(root->right);
	}
	return 0;
}



