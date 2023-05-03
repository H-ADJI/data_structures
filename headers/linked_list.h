

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct linked_list
{
    node *head;
} linked_list;

linked_list *create_linked_list(int arr[], int size);

void traverse(linked_list *list, int until);
void insert(int position, int element, linked_list *list);
void append(int element, linked_list *list);
void delete(int element, linked_list *list);
int search(int element, linked_list *list);
void repr_linked_list(linked_list *list);
