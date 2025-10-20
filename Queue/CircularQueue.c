//circular queue using array
#include <stdio.h>
#include <stdlib.h>
struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct CircularQueue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void enqueue(struct CircularQueue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue Overflow\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
int dequeue(struct CircularQueue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Queue Underflow\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
int isEmpty(struct CircularQueue q)
{
    return q.front == q.rear;
}
int isFull(struct CircularQueue q)
{
    return (q.rear + 1) % q.size == q.front;
}
int queueFront(struct CircularQueue q) 
{
    if (!isEmpty(q))
        return q.Q[(q.front + 1) % q.size];
    return -1;
}
int queueRear(struct CircularQueue q)
{
    if (!isEmpty(q))
        return q.Q[q.rear];
    return -1;
}
void display(struct CircularQueue q)
{
    int i = (q.front + 1) % q.size;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
}   
//Note: In circular queue, one space is wasted to differentiate between full and empty states.
//Thus, for a queue of size 'n', we can store 'n-1' elements.
int main()
{
    struct CircularQueue q;
    create(&q, 5); // Size 5 means we can store 4 elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(q);
    printf("\nDequeued: %d\n", dequeue(&q));
    printf("Front element: %d\n", queueFront(q));
    printf("Rear element: %d\n", queueRear(q));
    display(q);
    return 0;
}