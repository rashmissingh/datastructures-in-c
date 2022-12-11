struct node {
    int data;
	struct node *next;
};

int create_list(struct node **head, int nelems);
int push(struct node **head, int data);
int count_occurrence(struct node *head, int data);
int print_list(struct node *head);
int free_list(struct node **head);

