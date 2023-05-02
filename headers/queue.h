#define QueueSIZE 5

typedef struct queue
{
    int items[QueueSIZE];
    int front;
    int rear;

} queue;



queue *create_queue(void);
int queue_is_full(queue *q);
int queue_is_empty(queue *q);
void queue_shift(queue *q);
int queue_enqueue(queue *q, int element);
int queue_dequeue(queue *q);
void queue_visualize(queue *q);
int queue_peek(queue *q);
