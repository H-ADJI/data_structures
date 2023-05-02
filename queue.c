
#include <stdlib.h>
#include <stdio.h>
#define QueueSIZE 5

typedef struct queue
{
    int items[QueueSIZE];
    int front;
    int rear;

} queue;
queue *create_queue()
{
    queue *q = malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
int queue_is_full(queue *q)
{
    if ((q->front == 0) && (q->rear == QueueSIZE - 1))
    {
        return 1;
    }
    return 0;
}
int queue_is_empty(queue *q)
{
    if ((q->front == -1) && (q->rear == -1))
    {
        return 1;
    }
    return 0;
}
void queue_shift(queue *q)
{
    for (int i = q->front; i < QueueSIZE; i++)
    {
        q->items[i - q->front] = q->items[i];
    }
    q->rear -= q->front;
    q->front = 0;
}
int queue_enqueue(queue *q, int element)
{

    if (queue_is_full(q))
    {
        printf("the queue is full\n");
        return 0;
    }
    if (q->rear == QueueSIZE - 1)
    {
        queue_shift(q);
    }
    if (q->front == -1)
    {
        q->front += 1;
        q->rear += 1;
    }
    else
    {
        q->rear += 1;
    }
    q->items[q->rear] = element;
    return 1;
}
int queue_dequeue(queue *q)
{
    if (queue_is_empty(q))
    {
        printf("the queue is empty\n");
        return 0;
    }
    else
    {
        if (q->front == q->rear)
        {
            int last_el = q->items[q->rear];
            q->rear = -1;
            q->front = -1;
            return last_el;
        }
        else
        {
            q->front += 1;
            return q->items[q->front - 1];
        }
    }
}
void queue_visualize(queue *q)
{
    printf("---> ");
    for (int i = 0; i < QueueSIZE; i++)
        // if (q->front == i)
        //     printf("Front[%d] ", q->items[i]);
        // else if (q->rear == i)
        //     printf("Rear[%d] ", q->items[i]);
        // else
        printf("[ %d ] -- ", q->items[i]);
    printf("\n");
}
int queue_peek(queue *q)
{
    if (queue_is_empty(q))
    {
        printf("the queue is empty\n");
        return 0;
    }
    else
    {
        return q->items[q->front];
    }
}