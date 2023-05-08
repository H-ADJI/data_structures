
#include <stdio.h>
#include <stdlib.h>
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
void repr_linked_list(linked_list *list)
{
    node *next_node = list->head;
    printf("\n");
    printf("\n");
    while (next_node != NULL)
    {
        printf(" --> ");
        printf("%d", next_node->data);
        // printf(" | ");
        // printf("%p", next_node->next);
        next_node = next_node->next;
    }
    printf("\n");
    printf("\n");
}
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
    if (list->length < 2)
        printf("the list is already sorted");

    int visited = list->length - 1;
    while (visited > 0)
    {
        int flag = 0;
        node *current = list->head;
        node *next = current->next;
        node *previous = NULL;
        repr_linked_list(list);
        visited--;
        while (next != NULL)
        {
            if (current->data > next->data)
            {
                //  swap current and next
                if (previous == NULL)
                // case where we are at the list head
                {
                    current->next = next->next;
                    next->next = current;
                    list->head = next;
                }
                else
                // case where we are in the middle of the list
                {
                    previous->next = next;
                    current->next = next->next;
                    next->next = current;
                }
                //  in case of swap the previous element become what was the next element (before swap)
                previous = next;
                next = current->next;
                flag++;
            }
            else
            {
                previous = current;
                current = next;
                next = next->next;
            }
        }
        // track if there is no swap then list is sorted
        if (flag == 0)
            break;
    }
}
