#include <stdio.h>
#include <stdlib.h>
#define DS "stack"
#define StackSIZE 5

typedef struct stack
{
    int count;
    int items[StackSIZE];
} stack;

stack *create_stack()
{
    stack *st = malloc(sizeof(stack));
    st->count = 0;
    return st;
}
int stack_is_full(stack *st)
{
    if (st->count == StackSIZE)
    {
        return 1;
    }
    return 0;
}
int stack_is_empty(stack *st)
{
    if (st->count == 0)
    {
        return 1;
    }
    return 0;
}
int stack_push(int elem, stack *st)
{
    if (stack_is_full(st))
    {
        printf("cannot push element, the stack is full \n");
        return 0;
    }
    (st->items)[st->count] = elem;

    (st->count)++;
}
int stack_pop(stack *st)
{
    if (stack_is_empty(st))
    {
        printf("no element to pop, the stack is empty \n");
        return 0;
    }

    st->count--;
    return st->items[st->count + 1];
}

int stack_peek(stack *st)
{
    if (stack_is_empty(st))
    {
        printf("no element to peek, the stack is empty \n");
        return 0;
    }
    return (st->items)[st->count - 1];
}
void stack_repr(stack *st)
{
    for (int i = 0; i < 10; i++)
        printf("%d ", st->items[i]);
    printf("\n");
}