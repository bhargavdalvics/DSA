//METHOD2
//where elements are having their own priority value associated with them
//can also have duplicate priority values
//elements - 1,2,3,4,5,6,6,3,2,7
//smaller the value higher the priority
//insert  in increasing order of priority value
//while deleting delete from front(search-> findout -> delete from that position)

//insertion is O(n) time complexity
//deletion is O(1) time complexity
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
    int i;
    if (pq->rear == pq->size - 1)
        printf("Priority Queue Overflow\n");
    else
    {
        //find position of x
        for (i = pq->rear; i >= 0; i--)
        {
            if (x > pq->Q[i])
            {       
                pq->Q[i + 1] = pq->Q[i];
            }
            else
            {
                break;
            }
        }   
        pq->Q[i + 1] = x;
        pq->rear++;
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
    enqueue(&pq, 3);
    enqueue(&pq, 8);
    enqueue(&pq, 1);
    enqueue(&pq, 4);
    display(pq);
    printf("\nDequeued element: %d\n", dequeue(&pq));
    display(pq);
    return 0;
}