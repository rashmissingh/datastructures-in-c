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
int has_path_sum(struct tnode *root, int sum);
int print_tree(struct tnode *root);
void print_array(int *arr, int start, int end);

int main(int argc, int *argv[]) 
{
    struct tnode *pnode = NULL;
    int data = 0, sum = 0;
    
    printf("Enter space separated list of numbers to be inserted\n");

    scanf("%d", &data);
    while (data != -1) {
        pnode = insert_node(pnode, data);
        scanf("%d", &data);
    }

    printf("What is the sum to be looked up?\n");
    scanf("%d", &sum);
    has_path_sum(pnode, sum);

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

int has_path_sum(struct tnode *root, int sum) 
{
    int status = 0, status1 = 0, status2 = 0;
    if ((root->left == NULL) && (root->right == NULL)) {
        if ((root->data - sum) == 0) {
            printf("%d ", root->data);
            return 1;
        } else {
            return 0;
        }
    }

    if ((sum - root->data) > 0) {
        if (root->left != NULL) {
            status1 = has_path_sum(root->left, sum-root->data);
            if (status1 == 1)
                printf("%d ", root->data);
        }

        if (root->right != NULL) {
            status2 = has_path_sum(root->right, sum-root->data);
            if (status2 == 1) 
                printf("%d ", root->data);
        }
        if (status1 || status2) 
            status = 1;
    }

    return status;
}







