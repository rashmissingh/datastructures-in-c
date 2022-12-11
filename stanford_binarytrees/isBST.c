#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *insert_node(struct tnode *root, int data);
struct tnode *new_node(int data);
int isBST(struct tnode *root);
int print_tree(struct tnode *root);

int main(int argc, int *argv[]) 
{
    struct tnode *pnode = NULL;
    int data = 0, status = 0;
    
    printf("Enter space separated list of numbers to be inserted\n");

    /*scanf("%d", &data);
    while (data != -1) {
        pnode = insert_node(pnode, data);
        scanf("%d", &data);
    }*/

    /*custom tree 1
    pnode = new_node(5);
    pnode->left = new_node(6);
    pnode->right = new_node(7);
    */

    /*custom tree 2 */
    pnode = new_node(5);
    pnode->left = new_node(2);
    pnode->right = new_node(7);
    pnode->left->left = new_node(1);
    pnode->left->right = new_node(6);

    printf("Original tree: ");
    print_tree(pnode);
    printf("\n");

    status = isBST(pnode);

    if (status == 0)
        printf("Tree is BST\n");
    else 
        printf("Tree is not BST\n");

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

int isBST(struct tnode *root) 
{
    if ((root->left == NULL) && (root->right == NULL))
        return 0;

    if (root->left != NULL) {
        if (isBST(root->left)) {
            return 1;
        } else {
            if (root->left->data > root->data)
                return 1;
        }
    }

    if (root->right != NULL) {
        if (isBST(root->right) == 1) {
            return 1;
        } else {
            if (root->data >= root->right->data)
                return 1;
        }
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



