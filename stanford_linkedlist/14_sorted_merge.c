#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int create_list(struct node **head, int nelems);
int push(struct node **head, int data);
int move_node(struct node **dstlist, struct node **srclist);
struct node* sorted_merge(struct node **list1, struct node **list2);
int print_list(struct node *head);
int free_list(struct node **head);

void main(int argc, char *argv[]) 
{
    int i, nelems1 = 0, nelems2 = 0;
    struct node *list1 = NULL, *list2 = NULL, *mlist = NULL;

    if (argc < 3) {
        printf("Insufficient params, please enter number of elements in list 1 and 2\n");
        return;
    }

    nelems1 = atoi(argv[1]);
    create_list(&list1, nelems1);
    print_list(list1);

    nelems2 = atoi(argv[2]);
    create_list(&list2, nelems2);
    print_list(list2);

    mlist = sorted_merge(&list1, &list2);

    print_list(mlist);

    free_list(&mlist);

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

struct node* sorted_merge(struct node **list1, struct node **list2)
{
    struct node *mlist = NULL, *list = NULL, *pnode = NULL; 

    if ((*list1 == NULL) || (*list2 == NULL)) {
        mlist = (*list1 == NULL) ? *list2 : *list1;
        return mlist;
    }

    if ((*list1)->data <= (*list2)->data) {
        mlist = *list1; 
        list = mlist; 
        *list1 = (*list1)->next;
    } else {
        mlist = *list2; 
        list = mlist; 
        *list2 = (*list2)->next;
    }

    while ((*list1 != NULL) && (*list2 != NULL)) {
       if ((*list1)->data <= (*list2)->data) {
           pnode = *list1;
           *list1 = (*list1)->next;
           list->next = pnode;
           
       } else {
           pnode = *list2;
           *list2 = (*list2)->next;
           list->next = pnode; 
       }
       list = list->next;
    }
    list->next = (*list1 == NULL) ? *list2 : *list1;

    return mlist;
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


