
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
} linked_list;

linked_list *create_linked_list()
{
    node *h = malloc(sizeof(node));
    linked_list *list = malloc(sizeof(linked_list));
    h->data = 0;
    h->next = NULL;
    list->head = h;
}
