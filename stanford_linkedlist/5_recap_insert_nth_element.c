#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int create_list(struct node **ptr);
int push(struct node **head, int data);
int insert_nth(struct node **list, int data, int index);
int print_list(struct node *list);
void free_list(struct node **list);

void main(int argc, char **argv[])
{
    struct node *list = NULL;
    int data, index;

    create_list(&list);
    print_list(list);

    printf("Enter data to be inserted and it's index: ");
    scanf("%d %d", &data, &index);
    insert_nth(&list, data, index);

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

int insert_nth(struct node **list, int data, int index)
{
    int posn = 0;
    struct node *prev = NULL, *curr = NULL;

    /* assert(index>0;*/
    if ((*list == NULL) || (index == 0)) {
        push(list, data);
        return 0;
    }

    curr = *list; prev = curr;
    while ((curr != NULL) && (posn < index))  {
        prev = curr;
        curr = curr->next;
        posn++;
    }

    if ((curr == NULL) && (posn < index))
        return -1;

    push(&(prev->next), data);

    return 0;
}


