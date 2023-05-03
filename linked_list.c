
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
node *traverse(linked_list *list, int until)
{

    node *last_valid = list->head;
    node *next_node = last_valid->next;
    while (next_node != NULL)
    {
        until--;
        last_valid = next_node;
        next_node = next_node->next;
        if (until == 0)
            return last_valid;
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
        node *tail = traverse(list, -1);
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
void insert(int postition, int element, linked_list *list)
{

    if (postition == 0)
        printf("use the 'attach' function instead\n");
    else if (postition < 0)
        printf("use the 'append' function instead\n");
    else if (postition == 1)
    {
        node *new_node = malloc(sizeof(node));
        new_node->data = element;
        new_node->next = list->head->next;
        list->head->next = new_node;
    }
    else if (postition > list->length - 1)
        append(element, list);
    else
    {
        node *previous = traverse(list, postition - 1);
        node *current = traverse(list, postition);
        node *new_node = malloc(sizeof(node));
        new_node->data = element;
        new_node->next = current;
        previous->next = new_node;
    }
}

void delete(int element, linked_list *list)
{
    node *precedant = NULL;
    node *current = list->head;
    node *next_node = current->next;
    if (current->data == element)
        list->head = next_node;

    while (next_node != NULL)
    {
        precedant = current;
        current = next_node;
        next_node = current->next;
        if (current->data == element)
            break;
    }
    precedant->next = next_node;
    current->next = NULL;
}
int search(int element, linked_list *list)
{
    node *last_valid = list->head;
    node *next_node = last_valid->next;
    while (next_node != NULL)
    {
        if (last_valid->data == element)
        {
            printf("found element %d", element);
            printf("\n");
            return 1;
        }
        last_valid = next_node;
        next_node = next_node->next;
    }
    printf("can't find element %d", element);
    printf("\n");
    return 0;
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
    printf("\n");
}