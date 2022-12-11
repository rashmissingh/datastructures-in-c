#include <stdio.h>
#include <stdlib.h>
#include "ll_defs.h"

#define T 50
#define N 100
#define MAX_VALUE 100

int create_list(struct node **head, int nelems);
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
		printf("length of list = %d\n", length(head));
		free_list(&head);
    }

    return 0;
}

int create_list(struct node **head, int nelems)
{
    int count = 0, data = 0;
	struct node *newnode, *current = *head;
    
    if (nelems == 0) {
        return 1;
    }

    for(count = 0; count < nelems; count++) {
        scanf("%d", &data);
		push(&current, data);
    }
	*head = current;

    return 0;
}

/* Create list without the push method
int create_list(struct node **head, int nelems)
{
    int count = 0;
	struct node *newnode, *current = *head;
    
    if (nelems == 0) {
        return 1;
    }

    for(count = 0; count < nelems; count++) {
	    newnode = (struct node *)malloc(sizeof(struct node));
		newnode->next = current;
        scanf("%d", &(newnode->data));
		current = newnode;
    }
	*head = current;

    return 0;
}*/

int push(struct node **head, int data)
{
	struct node *newnode;
    
	newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
	newnode->next = *head;
	*head = newnode;

    return 0;
}

int length(struct node *head)
{
	struct node *current = head;
	int length = 0;

    while(current != NULL) {
		length++;
	    current = current->next;
    }
    return length;
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


