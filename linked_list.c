
#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct linked_list
{
    node *head;
    int length;
} linked_list;

// traverse the list and return the last element
node *traverse(linked_list *list)
{
    node *last_valid = list->head;
    node *next_node = last_valid->next;
    while (next_node != NULL)
    {
        last_valid = next_node;
        next_node = next_node->next;
    }

    return last_valid;
}
// add element at the tail of the linked list
void append(int element, linked_list *list)
{
    node *new_tail = malloc(sizeof(node));
    if (list->length == 0)
        list->head = new_tail;
    else
    {
        node *tail = traverse(list);
        tail->next = new_tail;
    }
    new_tail->data = element;
    new_tail->next = NULL;
    list->length++;
}
linked_list *create_linked_list(int arr[], int size)
{

    node *h = malloc(sizeof(node));
    linked_list *list = malloc(sizeof(linked_list));
    h->data = 0;
    h->next = NULL;
    list->head = h;
    list->length = 0;
    if (arr != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            append(arr[i], list);
        }
    }
    return list;
}
void insert(int element, linked_list *list)
{
}

void delete(int element, linked_list *list)
{
}
int search(int element, linked_list *list)
{
}
void sort(linked_list *list)
{
}
void repr_linked_list(linked_list *list)
{
    node *next_node = list->head;
    printf("\n");
    printf("\n");
    while (next_node != NULL)
    {
        printf(" --> ");
        printf("%d", next_node->data);
        printf(" | ");
        printf("%p", next_node->next);
        next_node = next_node->next;
    }
    printf("\n");
    printf("%d", list->length);
    printf("\n");
}