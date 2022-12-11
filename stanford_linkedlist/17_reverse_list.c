#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
	struct node *next;
};

int create_list(struct node **ptr);
int push(struct node **head, int data);
void reverse(struct node **list);
int print_list(struct node *list);
void free_list(struct node **list);

void main(int argc, char **argv[])
{
    struct node *list = NULL;

	create_list(&list);
	print_list(list);

	reverse(&list);

	print_list(list);

	return;
}

int create_list(struct node **list)
{
	int data;
	struct node *ptr = NULL;

	scanf("%d", &data);
    while (data != -1) {
        push(&ptr, data);
	    scanf("%d", &data);
	}
	*list = ptr;
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

void free_list(struct node **list)
{
	struct node *ptr = *list;

    while (*list != NULL) {
		ptr = *list;
		(*list) = (*list)->next;
		free(ptr);
	}
	return;
}

void reverse(struct node **list)
{
	struct node *prev = NULL, *curr = NULL, *next = NULL;

    if ((*list == NULL) || ((*list)->next == NULL)) {
        return;
    }

    curr = *list; prev = curr; next = curr->next;
	while (next != NULL) {
		prev = curr;
		curr = next;
		next = next->next;
		curr->next = prev;
	}
	
	(*list)->next = NULL;
	*list = curr;

	return;
}


