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

        printf("%d ", root->data);
    }
    return 0;
}




