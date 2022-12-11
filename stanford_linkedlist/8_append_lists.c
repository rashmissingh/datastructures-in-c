#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int create_list(struct node **head, int nelems);
int append(struct node **a, struct node **b);
int print_list(struct node *head);
int free_list(struct node **head);

void main(int argc, char *argv[]) 
{
    int count1 = 0, count2 = 0;
    struct node *list1 = NULL, *list2 = NULL;

    if (argc < 2) {
        printf("Insufficient params, please enter number of elements in list 1 and 2\n");
        return;
    }

    count1 = atoi(argv[1]);
    create_list(&list1, count1);
    print_list(list1);

    count2 = atoi(argv[2]);
    create_list(&list2, count2);
    print_list(list2);

    append(&list1, &list2);
    print_list(list1);

    free_list(&list1);
    free_list(&list2);

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

int append(struct node **a, struct node **b)
{
    struct node *ptr = *a;

    if (ptr == NULL) {
        *a = *b;
        *b = NULL;
        return 0;
    }

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = *b;
    *b = NULL;

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


