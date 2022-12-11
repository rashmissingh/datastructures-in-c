#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int create_list(struct node **head, int nelems);
int push(struct node **head, int data);
int pop(struct node **head);
int print_list(struct node *head);
int free_list(struct node **head);

void main(int argc, char *argv[]) 
{
    int i, nelems = 0, data = 0, npop = 0;
    struct node *head = NULL;

    if (argc < 2) {
        printf("Insufficient params, please enter number of elements in list\n");
        return;
    }

    nelems = atoi(argv[1]);
    create_list(&head, nelems);
    print_list(head);

    printf("How many numbers to be popped? ");
    scanf("%d", &npop);
    for (i=0; i<npop; i++) {
        data = -1;    
        data = pop(&head);
        printf("Popped %d : %d\n", i, data);
        print_list(head);
    }

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

int pop(struct node **head)
{
    int data = -1, posn = 0;
    struct node *ptr = *head;

    /* assert(ptr !=NULL) */
    if (ptr == NULL)
        return -1;

    data = ptr->data;
    *head = ptr->next;
    free(ptr);

    return data;
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


