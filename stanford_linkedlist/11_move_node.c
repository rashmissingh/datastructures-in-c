#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int create_list(struct node **head, int nelems);
int push(struct node **head, int data);
int move_node(struct node **dstlist, struct node **srclist);
int print_list(struct node *head);
int free_list(struct node **head);

void main(int argc, char *argv[]) 
{
    int i, nelems1 = 0, nelems2 = 0, data = 0, nmove = 0;
    struct node *srclist = NULL, *dstlist = NULL;

    if (argc < 3) {
        printf("Insufficient params, please enter number of elements in list 1 and 2\n");
        return;
    }

    nelems1 = atoi(argv[1]);
    create_list(&srclist, nelems1);
    print_list(srclist);

    nelems2 = atoi(argv[2]);
    create_list(&dstlist, nelems2);
    print_list(dstlist);

    scanf("%d", &nmove);
    for (i=0; i<nmove; i++) {
        move_node(&dstlist, &srclist);
        print_list(srclist);
        print_list(dstlist);
    }

    free_list(&srclist);
    free_list(&dstlist);

    return;
}

int create_list(struct node **head, int nelems)
{
    int i = 0, data = 0;

    printf("Enter the list elements in space separated format\n");
    for(i=0; i<nelems; i++)
    {
        scanf("%d", &data);
        push(head, data);
    }
    
    return 0;
}

int push(struct node **head, int data)
{
    struct node *newnode = NULL;

    newnode = (struct node*) malloc (sizeof(struct node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;

    return 0;
}

int move_node(struct node **dstlist, struct node **srclist)
{
    struct node *ptr = *srclist;

    /* assert(ptr !=NULL) */
    if (ptr == NULL)
        return -1;

    *srclist = (*srclist)->next;
    ptr->next = *dstlist;
    *dstlist = ptr;

    return 0;
}

int print_list(struct node *head)
{
    struct node *ptr = head;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return 0;
}

int free_list(struct node **head)
{
    struct node *ptr = *head, *prev;

    while (ptr != NULL) {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
    *head = NULL;

    return 0;
}


