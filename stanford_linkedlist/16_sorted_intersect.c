#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int create_list(struct node **head, int nelems);
int push(struct node **head, int data);
struct node *sorted_intersect(struct node *list1, struct node *list2);
int print_list(struct node *head);
int free_list(struct node **head);

void main(int argc, char *argv[]) 
{
    int i, nelems1 = 0, nelems2 = 0, data = 0, nmove = 0;
    struct node *list1 = NULL, *list2 = NULL, *intersect = NULL;

    if (argc < 3) {
        printf("Insufficient params, please enter number of elements in list 1 and 2\n");
        return;
    }

    nelems1 = atoi(argv[1]);
    create_list(&list1, nelems1);
    print_list(list1);

    nelems2 = atoi(argv[2]);
    create_list(&list2, nelems2);
    print_list(list2);

    intersect = sorted_intersect(list1, list2);
    print_list(intersect);

    free_list(&list1);
    free_list(&list2);
    free_list(&intersect);

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

struct node *sorted_intersect(struct node *list1, struct node *list2)
{
    struct node *intersect = NULL, *ptr1 = list1, *ptr2 = list2;

    if ((ptr1 == NULL) || (ptr2 == NULL)) {
        return intersect;
    }

    while ((ptr1 != NULL) && (ptr2 != NULL)) {
        if (ptr1->data == ptr2->data) {
            push(&intersect, ptr1->data);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else {
            if (ptr1->data < ptr2->data) {
                ptr1 = ptr1->next;
            } else {
                ptr2 = ptr2->next;
            }
        }
    }
    return intersect;
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


