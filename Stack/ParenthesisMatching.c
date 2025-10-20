//parenthesis matching.c
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    char *S;
};
void create(struct Stack *st)
{
    printf("Enter size of stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (char *)malloc(st->size * sizeof(char));
}
void push(struct Stack *st, char x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
char pop(struct Stack *st)
{
    char x = '\0';
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
int isFull(struct Stack st)
{
    return st.top == st.size - 1;
}
char stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top];
    return '\0';
}

int isMatchingPair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return 1;
    if (opening == '{' && closing == '}')
        return 1;
    if (opening == '[' && closing == ']')
        return 1;
    return 0;
}
int areParenthesesBalanced(char *exp)
{
    struct Stack st;
    create(&st);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            {
                push(&st, exp[i]);
            }
            else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if (isEmpty(st))
                    return 0;
                char poppedChar = pop(&st);
                if (!isMatchingPair(poppedChar, exp[i]))
                    return 0;
            }
    }
    return isEmpty(st);
}
int main()
{
    char exp[100];
    printf("Enter an expression: ");
    scanf("%s", exp);
    if (areParenthesesBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}


