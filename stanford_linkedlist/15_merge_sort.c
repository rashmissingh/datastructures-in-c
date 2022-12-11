#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int create_list(struct node **head, int nelems);
int push(struct node **head, int data);
int length_list(struct node *list);
int split(struct node *list, struct node **a, struct node **b);
struct node* sorted_merge(struct node **list1, struct node **list2);
int merge_sort(struct node **list);
int print_list(struct node *head);
int free_list(struct node **head);

void main(int argc, char *argv[]) 
{
    int nelems = 0;
    struct node *list = NULL;

    if (argc < 2) {
        printf("Insufficient params, please enter number of elements in list\n");
        return;
    }

    nelems = atoi(argv[1]);
    create_list(&list, nelems);
    print_list(list);

    merge_sort(&list);

    print_list(list);
    free_list(&list);

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

int split(struct node *source, struct node **first, struct node **second)
{
    struct node *ptr = source;
    int len = 0, half = 0, count = 0;

    if (source == NULL) {
        *first = NULL;
        *second = NULL;
        return 0;
    }

    *first = source;
    len = length_list(source);
    half = (len / 2) + (len % 2);

    count = 1;
    while (count < half) {
        ptr = ptr->next;
        count++;
    }
    *second = ptr->next;
    ptr->next = NULL;

    return 0;
}

int length_list(struct node *list) 
{
    struct node *ptr = list;
    int len = 0;

    while (ptr != NULL) {
        len++;
        ptr = ptr->next;
    }

    return len;
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

struct node* sorted_merge(struct node **list1, struct node **list2)
{
    struct node *mlist = NULL, *list = NULL, *pnode = NULL; 

    if ((*list1 == NULL) || (*list2 == NULL)) {
        mlist = (*list1 == NULL) ? *list2 : *list1;
        return mlist;
    }

    if ((*list1)->data <= (*list2)->data) {
        mlist = *list1;
        mlist->next = sorted_merge(&((*list1)->next), list2);
    } else {
        mlist = *list2;
        mlist->next = sorted_merge(list1, &((*list2)->next));
    }

    return mlist;
}


int merge_sort(struct node **list) 
{
    struct node *list1 = NULL, *list2 = NULL, *mlist = NULL;

    if (*list == NULL)
        return 0;

    split(*list, &list1, &list2);
    merge_sort(&list1);
    merge_sort(&list2);

    mlist = sorted_merge(&list1, &list2);

    *list = mlist;
    return 0;
}




