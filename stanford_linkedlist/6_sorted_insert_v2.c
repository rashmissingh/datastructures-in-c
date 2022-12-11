#include <stdio.h>
#include <stdlib.h>
#include "ll_defs.h"

#define T 50
#define N 100
#define MAX_VALUE 100

int create_sorted_list(struct node **head, int nelems);
int sorted_insert(struct node **head, struct node *newnode);
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
        create_sorted_list(&head, nelems);
        print_list(head);
        free_list(&head);
    }

    return 0;
}

int create_sorted_list(struct node **head, int nelems)
{
    int count = 0, data = 0;
    struct node *newnode = NULL;
    
    if (nelems == 0) {
        return 1;
    }

    for(count = 0; count < nelems; count++) {
        scanf("%d", &data);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
    
        sorted_insert(head, newnode);
    }

    return 0;
}

int sorted_insert(struct node **head, struct node *newnode)
{
    struct node *current = *head, *prev = *head;

    if ((*head == NULL) || ((*head)->data > newnode->data)) {
        newnode->next = *head;
        *head = newnode;
        return 0;
    }

    while ((current != NULL) && (current->data < newnode->data)) {
        prev = current;
        current = current->next;
    }
    newnode->next = prev->next;
    prev->next = newnode;

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


