#define StackSIZE 5
typedef struct stack
{
    int count;
    int items[StackSIZE];
} stack;

stack *create_stack();
int stack_is_full(stack *st);
int stack_is_empty(stack *st);
int stack_push(int elem, stack *st);
int stack_pop(stack *st);
int stack_peek(stack *st);
void stack_repr(stack *st);