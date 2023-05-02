

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct linked_list
{
    node *head;
} linked_list;

linked_list *create_linked_list(void);
