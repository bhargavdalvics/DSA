

// ### Operator Precedence Table (for Infix to Postfix Conversion)

// | Operator | Outside Stack Precedence | Inside Stack Precedence |
// |----------|--------------------------|-------------------------|
// | ( +, - ) | 1                        | 2                       |
// | ( *, / ) | 3                        | 4                       |
// | ( ^) (exponent) | 6                    | 5                       |
// | ( ( )     | 7                        | 0                       |
// | ( ) )     | 0                        | — (not pushed)          |

// ---

// ### Rules:
// - **Outside Stack Precedence**: Used when the operator is outside the stack (about to be pushed).
// - **Inside Stack Precedence**: Used when the operator is already inside the stack.
// - If **outside precedence** > **inside precedence** → push the operator.
// - If **outside precedence** ≤ **inside precedence** → pop from stack until condition is satisfied.
// - \( ( \) has high outside precedence (7) but low inside precedence (0), so it pushes easily but operators after it can push too.
// - \( ) \) has 0 outside precedence, so it causes popping until \( ( \) is found.

// ---



//infixToPrefix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *convert(char *infix);      // Function to convert infix to prefix
int precedence(char x);
struct Stack
{
    int size;
    int top;
    char *S;
};
void create(struct Stack *st)     // Function to create stack
{
    st->size = 100;
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
char stackTop(struct Stack st)
{
    if (st.top != -1)
        return st.S[st.top];
    return '\0';
}
int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3;
    return 0;
}
char *convert(char *infix)        // Function to convert infix to prefix
{ 
    struct Stack st;
    create(&st);
    char *prefix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = strlen(infix) - 1, j = 0;      // strlen(infix)-1 to start from the end
    while (i >= 0)                        // Traverse the infix expression from right to left
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9'))
        {
            prefix[j++] = infix[i--];
        }
        else if (infix[i] == ')')
        {
            push(&st, infix[i--]);
        }
        else if (infix[i] == '(')
        {
            while (st.top != -1 && stackTop(st) != ')')    // Pop until ')' is found
            {
                prefix[j++] = pop(&st);
            }
            pop(&st);
            i--;
        }
        else
        {
            while (st.top != -1 && precedence(stackTop(st)) > precedence(infix[i]))   // Note the '>' for right to left traversal
            {
                prefix[j++] = pop(&st);
            }
            push(&st, infix[i--]);
        }
    }
    while (st.top != -1)         // Pop all remaining operators
    {
        prefix[j++] = pop(&st);
    }
    prefix[j] = '\0';
    // Reverse the prefix string
    for (int k = 0; k < j / 2; k++)       // Reverse the string
    {
        char temp = prefix[k];
        prefix[k] = prefix[j - k - 1];
        prefix[j - k - 1] = temp;
    }
    return prefix;
}
int main()
{
    char infix[100];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    char *prefix = convert(infix);     // Convert infix to prefix
    printf("Prefix Expression: %s\n", prefix);
    free(prefix);            // Free allocated memory
    return 0;
}
// --- IGNORE ---

//evalution of postfix
// ### Parenthesis Matching using Stack
// ### Related Code Snippets
// ### Infix to Postfix Conversion using Stack
// ### Stack Implementation in C
// ### Stack Implementation in C

// #include <stdio.h>
// #include <stdlib.h>
// struct Stack
// {
//     int size;
//     int top;
//     int *S;
// };
// void create(struct Stack *st)
// {
//     printf("Enter size of stack: ");
//     scanf("%d", &st->size);
//     st->top = -1;
//     st->S = (int *)malloc(st->size * sizeof(int));
// }
// void push(struct Stack *st, int x)
// {
//     if (st->top == st->size - 1)

//         printf("Stack Overflow\n");
//     else
//     {
//         st->top++;
//         st->S[st->top] = x;
//     }
// }
// int pop(struct Stack *st)
// {
//     int x = -1;
//     if (st->top == -1)        
//         printf("Stack Underflow\n");
//     else
//     {
//         x = st->S[st->top--];
//     }
//     return x;
// }
// int peek(struct Stack st, int index)
// {
//     int x = -1;
//     if (st.top - index + 1 < 0) 
//         printf("Invalid Index\n");
//     else
//     {
//         x = st.S[st.top - index + 1];
//     }
//     return x;
// }
// int isEmpty(struct Stack st)
// {
//     return st.top == -1;
// }
// int isFull(struct Stack st)
// {
//     return st.top == st.size - 1;
// }
// int stackTop(struct Stack st)
// {
//     if (!isEmpty(st))
//         return st.S[st.top];
//     return -1;
// }
