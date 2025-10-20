//priority queues 
//for eg. 

//METHOD1
//elements -> A(1), B(2), C(3), D(1) numeric value indicates priority
//create array on basis of priority
//array1- A,D (priority 1)
//array2- B (priority 2)
//array3- C (priority 3)
//while inserting element we insert in respective array on basis of priority
//while deleting element we delete from highest priority array first(ie. array1) if empty
//then from array2 and so on
#include <stdio.h>
#include <stdlib.h>
struct PriorityQueue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct PriorityQueue *pq, int size)
{
    pq->size = size;
    pq->front = pq->rear = -1;
    pq->Q = (int *)malloc(pq->size * sizeof(int));
}
void enqueue(struct PriorityQueue *pq, int x)
{
    if (pq->rear == pq->size - 1)
        printf("Priority Queue Overflow\n");
    else
    {
        pq->rear++; 
        pq->Q[pq->rear] = x;
    }
}
int dequeue(struct PriorityQueue *pq)
{
    int x = -1;
    if (pq->front == pq->rear)
        printf("Priority Queue Underflow\n");
    else
    {
        pq->front++;
        x = pq->Q[pq->front];
    }
    return x;
}
int isEmpty(struct PriorityQueue pq)
{
    return pq.front == pq.rear;
}
int isFull(struct PriorityQueue pq)
{
    return pq.rear == pq.size - 1;
}
int queueFront(struct PriorityQueue pq)
{
    if (!isEmpty(pq))
        return pq.Q[pq.front + 1];
    return -1;
}
int queueRear(struct PriorityQueue pq)
{
    if (!isEmpty(pq))
        return pq.Q[pq.rear];
    return -1;
}
void display(struct PriorityQueue pq)
{
    int i;
    for (i = pq.front + 1; i <= pq.rear; i++)
        printf("%d ", pq.Q[i]);
}
int main()
{
    struct PriorityQueue pq;
    create(&pq, 10);
    enqueue(&pq, 5);
    enqueue(&pq, 15);
    enqueue(&pq, 25);
    display(pq);
    printf("\nDequeued element: %d\n", dequeue(&pq));
    display(pq);
    return 0;
}





