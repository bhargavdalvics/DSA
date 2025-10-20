#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("Queue Overflow\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)

        printf("Queue Underflow\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}
int isFull(struct Queue q)
{
    return q.rear == q.size - 1;
}
int queueFront(struct Queue q)
{
    if (!isEmpty(q))

        return q.Q[q.front + 1];
    return -1;
}
int queueRear(struct Queue q)
{
    if (!isEmpty(q))
        return q.Q[q.rear];
    return -1;
}
void display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}
int main()
{
    struct Queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(q);
    printf("Dequeued: %d\n", dequeue(&q));
    display(q);
    printf("Front element: %d\n", queueFront(q));
    printf("Rear element: %d\n", queueRear(q));
    return 0;
}