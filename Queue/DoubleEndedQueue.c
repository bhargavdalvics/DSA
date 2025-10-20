
//DEqueue - can use it as FIFO
//in DEqueue we can use front and rear both ends for insertion and deletion
//NOTE:
// I/P Restricted DEQueue
// | Position | Insert | Delete |
// | -------- | ------ | ------ |
// | Front    | ❌      | ✅      |
// | Rear     | ✅      | ✅      |

// O/P Restricted DEQueue
// | Position | Insert | Delete |
// | -------- | ------ | ------ |
// | Front    | ✅      | ✅      |
// | Rear     | ✅      | ❌      |

#include <stdio.h>
#include <stdlib.h>
struct DEqueue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct DEqueue *dq, int size)
{
    dq->size = size;
    dq->front = dq->rear = -1;
    dq->Q = (int *)malloc(dq->size * sizeof(int));
}
void insertFront(struct DEqueue *dq, int x)
{
    if (dq->front == -1)
        printf("DEqueue Overflow\n");
    else
    {
        dq->Q[dq->front--] = x;
    }
}
void insertRear(struct DEqueue *dq, int x)
{
    if (dq->rear == dq->size - 1)
        printf("DEqueue Overflow\n");
    else
    {
        dq->Q[++dq->rear] = x;
    }
}
int deleteFront(struct DEqueue *dq)
{
    int x = -1;
    if (dq->front == dq->rear)
        printf("DEqueue Underflow\n");
    else
    {
        x = dq->Q[++dq->front];
    }
    return x;
}
int deleteRear(struct DEqueue *dq)
{
    int x = -1;
    if (dq->front == dq->rear)
        printf("DEqueue Underflow\n");
    else
    {
        x = dq->Q[dq->rear--];
    }
    return x;
}
int isEmpty(struct DEqueue dq)
{
    return dq.front == dq.rear;
}
int isFull(struct DEqueue dq)
{
    return dq.front == -1 && dq.rear == dq.size - 1;
}
int getFront(struct DEqueue dq)
{
    if (!isEmpty(dq))
        return dq.Q[dq.front + 1];
    return -1;
}
int getRear(struct DEqueue dq)
{
    if (!isEmpty(dq))
        return dq.Q[dq.rear];
    return -1;
}
void display(struct DEqueue dq)
{
    for (int i = dq.front + 1; i <= dq.rear; i++)
        printf("%d ", dq.Q[i]);
}

int main(void)
{
    struct DEqueue dq;
    create(&dq, 10);

    // Insert some elements at rear
    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertRear(&dq, 30);

    // Insert at front (will fail initially because front == -1 indicates no space on left)
    // Move front forward by deleting one from front to allow insertFront demonstration
    (void)deleteFront(&dq); // removes 10
    insertFront(&dq, 5);    // now inserts at index 0

    printf("Deque contents: ");
    display(dq);
    printf("\nFront: %d, Rear: %d\n", getFront(dq), getRear(dq));

    // Clean up allocated memory
    free(dq.Q);

    return 0;
}  
//Note: DEqueue can be implemented using circular array to utilize space efficiently

