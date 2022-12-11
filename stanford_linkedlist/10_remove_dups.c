#include <stdio.h>
#include <stdlib.h>
#include "ll_defs.h"

#define T 50
#define N 100
#define MAX_VALUE 100

int create_list(struct node **head, int nelems);
int push(struct node **head, int data);
int remove_dups(struct node **head);
int print_list(struct node *head);
int free_list(struct node **head);

int main(int argc, char *argv[])
{
    int i = 0, nelems = 0, test_count = 0; 
    struct node *head = NULL;

    scanf("%d", &test_count);
    if (test_count > T) {
        printf("Executing first %d tests\n", T);
        test_count = T;
    }
    
    for (i = 0; i < test_count; i++) {
        scanf("%d", &nelems); 
        create_list(&head, nelems);
        print_list(head);
        remove_dups(&head);
        print_list(head);
        free_list(&head);
    }

    return 0;
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

int remove_dups(struct node **head)
{
    struct node *current = *head, *prev = *head;

    if ((*head == NULL) || ((*head)->next == NULL)) {
        return 0;
    }

    current = current->next;
    while (current != NULL) {
        if (prev->data == current->data) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return 0;
}

int free_list(struct node **head)
{
    struct node *prev, *current = *head;

    while(current != NULL) {
        prev = current->next;
        free(current);
        current = prev;
    }
    *head = NULL;

    return 0;
}


int print_list(struct node *head)
{
    struct node *current = head;

    for(current = head; current != NULL; current = current->next) {
        printf("%d ", current->data);
    }
    printf("\n");

    return 0;
}


