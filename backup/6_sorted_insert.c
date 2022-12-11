#include <stdio.h>
#include <stdlib.h>
#include "ll_defs.h"

#define T 50
#define N 100
#define MAX_VALUE 100

int create_sorted_list(struct node **head, int nelems);
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
        create_sorted_list(&head, nelems);
        print_list(head);
		free_list(&head);
    }

    return 0;
}

int create_sorted_list(struct node **head, int nelems)
{
    int count = 0, data = 0;
	struct node *newhead = *head, *prev, *current = *head;
    
    if (nelems == 0) {
        return 1;
    }

    for(count = 0; count < nelems; count++) {
        scanf("%d", &data);
		current = *head; prev = current;
		if (current == NULL) {  /* this is the very first node */
		    push(head, data);
			continue;
        }
		while ((current != NULL) && (current->data < data)) {
		    prev = current;
			current = current->next;
		}
		if (current == NULL) {  /* this is the last node */
		    push(&(prev->next), data);
			continue;
        }
		if ((current->data > data) && (current == prev)) { /* the new number is smaller than the list */
            push(&current, data);
			*head = current;
			continue;
		}

	    push(&(prev->next), data);
    }

    return 0;
}

int push(struct node **head, int data)
{
	struct node *newnode;
    
	newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
	newnode->next = *head;
	*head = newnode;

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


