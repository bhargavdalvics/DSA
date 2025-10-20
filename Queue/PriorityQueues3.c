
//QUEUE USING TWO STACKS
//use two stacks s1 and s2
//for insertion-push element onto s1
//for deletion-if s2 is not empty pop from s2
//if s2 is empty pop all elements from s1 and push them onto s2
//then pop from s2
//insertion is O(1) time complexity
//deletion is amortized O(1) time complexity
#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *S;
};
void createStack(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));      
}
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}
int isEmpty(struct Stack st)
{
    return st.top == -1;
}
struct QueueUsingStacks
{
    struct Stack s1;
    struct Stack s2;
};
void createQueueUsingStacks(struct QueueUsingStacks *qus, int size)
{
    createStack(&qus->s1, size);
    createStack(&qus->s2, size);
}
void enqueue(struct QueueUsingStacks *qus, int x)
{
    push(&qus->s1, x);
}
int dequeue(struct QueueUsingStacks *qus)
{
    int x = -1;
    if (isEmpty(qus->s2))
    {
        while (!isEmpty(qus->s1))
        {
            int y = pop(&qus->s1);
            push(&qus->s2, y);
        }
    }
    x = pop(&qus->s2);
    return x;
}
int main()
{
    struct QueueUsingStacks qus;
    createQueueUsingStacks(&qus, 5);
    enqueue(&qus, 10);
    enqueue(&qus, 20);
    enqueue(&qus, 30);
    printf("Dequeued: %d\n", dequeue(&qus));
    printf("Dequeued: %d\n", dequeue(&qus));
    enqueue(&qus, 40);
    printf("Dequeued: %d\n", dequeue(&qus));
    printf("Dequeued: %d\n", dequeue(&qus));
    return 0;
}