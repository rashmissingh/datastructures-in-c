#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
	struct node *next;
};

int create_list(struct node **head, int nelems);
int push(struct node **head, int data);
int move_node(struct node **dstlist, struct node **srclist);
int alternate_split(struct node **head, struct node **dstlist, struct node **srclist);
int print_list(struct node *head);
int free_list(struct node **head);

void main(int argc, char *argv[]) 
{
    int i, nelems = 0;
	struct node *head = NULL, *oddlist = NULL, *evenlist = NULL;

    if (argc < 2) {
        printf("Insufficient params, please enter number of elements in list\n");
		return;
    }

	nelems = atoi(argv[1]);
    create_list(&head, nelems);
	print_list(head);

    alternate_split(&head, &evenlist, &oddlist);
	print_list(evenlist);
	print_list(oddlist);

	free_list(&head);
	free_list(&evenlist);
	free_list(&oddlist);

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

int move_node(struct node **dstlist, struct node **srclist)
{
    struct node *ptr = *srclist;

    /* assert(ptr !=NULL) */
    if (ptr == NULL)
        return -1;

    *srclist = (*srclist)->next;
    ptr->next = *dstlist;
    *dstlist = ptr;

    return 0;
}

int alternate_split(struct node **head, struct node **evenlist, struct node **oddlist)
{
	int length = 0, remainder = 0;

	if (*head == NULL)
	    return 0;

	while (*head != NULL) {
	    remainder = length % 2;
		if (remainder == 0) {
            move_node(evenlist, head);
		} else {
            move_node(oddlist, head);
		}
	    length++;
	}

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


