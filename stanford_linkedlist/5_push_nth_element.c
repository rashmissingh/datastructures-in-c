#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int create_list(struct node **head, int nelems);
int push(struct node **head, int data);
int push_nth_element(struct node **head, int index, int data);
int print_list(struct node *head);
int free_list(struct node **head);

void main(int argc, char *argv[]) 
{
    int nelems = 0, data = 0, index = 0, status = 0;
    struct node *head = NULL;

    if (argc < 2) {
        printf("Insufficient params, please enter number of elements in list\n");
        return;
    }

    nelems = atoi(argv[1]);
    create_list(&head, nelems);

    printf("Where is the element to be inserted? "); scanf("%d", &index);
    printf("Number to be inserted? "); scanf("%d", &data);
    status = push_nth_element(&head, index, data);

    print_list(head);
    free_list(&head);

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

int push_nth_element(struct node **head, int index, int data)
{
    int posn = 0;
    struct node *current = *head, *prev = *head;

    if (index < 0)
        return -1;

    if ((current == NULL) || (index == 0)) {
        push(&current, data);
        *head = current;
        return 0;
    }

    while ((current != NULL) && (posn < index)) {
        prev = current;
        current = current->next;
        posn++;
    }
    if ((current == NULL) && (posn < index)) /* index > length(list) */
        return -1;
    push((&prev->next), data);

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


