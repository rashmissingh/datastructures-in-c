#include <stdio.h>
#include <stdlib.h>
#include "ll_defs.h"

#define T 50
#define N 100
#define MAX_VALUE 100

int create_list(struct node **head, int nelems);
int sorted_insert(struct node **head, struct node *pnode);
int sort_list(struct node **head);
int push(struct node **head, int data);
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
        sort_list(&head);
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

int sort_list(struct node **head)
{
    struct node *newlist = NULL, *oldlist = NULL, *pnode = NULL;
    
    if (((*head) == NULL) || ((*head)->next == NULL)) {
        return 0;
    }
    newlist = *head; oldlist = (*head)->next; newlist->next = NULL;
    while (oldlist != NULL) {
        pnode = oldlist;
        oldlist = oldlist->next;
        pnode->next = NULL;
        sorted_insert(&newlist, pnode);
    }
    *head = newlist;
    
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


