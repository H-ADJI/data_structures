#include <stdio.h>
#include <stdlib.h>
#define DS "stack"
#define SIZE 10

typedef struct stack
{
    int count;
    int items[SIZE];
} stack;

stack *create_stack()
{
    stack *st = malloc(sizeof(stack));
    st->count = 0;
    return st;
}
int is_full(stack *st)
{
    if (st->count == SIZE)
    {
        return 1;
    }
    return 0;
}
int is_empty(stack *st)
{
    if (st->count == 0)
    {
        return 1;
    }
    return 0;
}
int push(int elem, stack *st)
{
    if (is_full(st))
    {
        printf("cannot push element, the stack is full \n");
        return 0;
    }
    (st->items)[st->count] = elem;

    (st->count)++;
}
int pop(stack *st)
{
    if (is_empty(st))
    {
        printf("no element to pop, the stack is empty \n");
        return 0;
    }

    st->count--;
    return st->items[st->count + 1];
}

int peek(stack *st)
{
    if (is_empty(st))
    {
        printf("no element to peek, the stack is empty \n");
        return 0;
    }
    return (st->items)[st->count - 1];
}
void repr(stack *st)
{
    for (int i = 0; i < 10; i++)
        printf("%d ", st->items[i]);
    printf("\n");
}
int main()
{

    stack *st = create_stack();
    push(1, st);
    printf("%d\n", peek(st));
    push(2, st);
    printf("%d\n", peek(st));
    int el = pop(st);
    printf("%d\n", peek(st));
    free(st);
}