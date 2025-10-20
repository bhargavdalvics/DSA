#include<stdio.h>
struct Stack
{
    int size;
    int top;
    int *S;
};
void create(struct Stack *st)
{
    printf("Enter size of stack: ");
    scanf("%d", &st->size);
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
int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)

        printf("Invalid Index\n");
    else
    {
        x = st.S[st.top - index + 1];
    }
    return x;
}
int isEmpty(struct Stack st)
{
    return st.top == -1;
}
int isFull(struct Stack st)
{
    return st.top == st.size - 1;
}
int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top];
    return -1;
}
void display(struct Stack st)
{
    for (int i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}
int main()
{
    struct Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    display(st);
    printf("Popped element: %d\n", pop(&st));
    display(st);
    printf("Element at index 1: %d\n", peek(st, 1));
    printf("Top element: %d\n", stackTop(st));
    if (isEmpty(st))

        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
    if (isFull(st))
        printf("Stack is full\n");
    else

        printf("Stack is not full\n");
    return 0;
}

