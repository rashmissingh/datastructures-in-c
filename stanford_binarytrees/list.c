#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
	struct node *next;
};

int create_list(struct node **head, int nelems);
int push(struct node **head, int data);
int count_occurrence(struct node *head, int data);
int print_list(struct node *head);
int free_list(struct node **head);

void main(int argc, char *argv[]) 
{
    int nelems = 0, data = 0, count = 0;
	struct node *head = NULL;

    if (argc < 2) {
        printf("Insufficient params, please enter number of elements in list\n");
		return;
    }

	nelems = atoi(argv[1]);
    create_list(&head, nelems);

	printf("What number should be looked up? ");
	scanf("%d", &data);
	count = count_occurrence(head, data);
	printf("%d occurs %d times\n", data, count);

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

int count_occurrence(struct node *head, int data)
{
	int count = 0;
	struct node *ptr = head;

	while (ptr != NULL) {
	    if (ptr->data == data)
		    count++;
        ptr = ptr->next;
	}

    return count;
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


