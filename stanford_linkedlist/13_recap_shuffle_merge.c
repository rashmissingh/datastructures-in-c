#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int create_list(struct node **ptr);
struct node *shuffle_merge(struct node **list1, struct node **list2);
int print_list(struct node *list);

void main(int argc, char **argv[])
{
    struct node *list1 = NULL, *list2 = NULL, *mlist = NULL;

    create_list(&list1);
    print_list(list1);
    create_list(&list2);
    print_list(list2);

    mlist = shuffle_merge(&list1, &list2);

    print_list(mlist);

    return;
}

int create_list(struct node **list)
{
    int data;
    struct node *ptr = NULL, *newnode = NULL;

    scanf("%d", &data);
    while (data != -1) {
        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->next = ptr;
        newnode->data = data;
        ptr = newnode;
        scanf("%d", &data);
    }
    *list = ptr;
    return 0;
}


int print_list(struct node *list)
{
    int data;
    struct node *ptr = list;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;
}


struct node *shuffle_merge(struct node **list1, struct node **list2)
{
    int over = 0;
    struct node *mlist = NULL, *ptr = NULL;

    mlist = (*list1 == NULL) ? *list2 : *list1;
    ptr = mlist;
    while ((*list1 != NULL) && (*list2 != NULL))  {
        *list1 = (*list1)->next;
        ptr->next = *list2;
        ptr = ptr->next;

        *list2 = (*list2)->next;
        ptr->next = *list1;
        ptr = ptr->next;
    }

    return mlist;
}


