//infixToPostfix
// Convert infix expression to postfix expression using stack
//make one stack for operators
// Scan the infix expression from left to right
//the give no.1 precedance to +-
//give no.2 precedance to */
//give no.3 precedance to ^
//check from left to right
//if precedance of any operator is less than or equal to top of stack then pop all the operators from stack and add to postfix expression
//then push the current operator to stack
//in last pop all the operators from stack and add to postfix expression
// # Infix to Postfix Conversion

// **Infix Expression:** `a + b * c - d / e`

// | Symbol | Stack      | Postfix    |
// |--------|------------|------------|
// | a      | —          | a          |
// | +      | +          | a          |
// | b      | +          | ab         |
// | *      | *, +       | ab         |
// | c      | *, +       | abc        |
// | –      | –          | abc*+      |
// | d      | –          | abc*+d     |
// | /      | /, -       | abc*+d     |
// | e      | /, -       | abc*+de    |
// | end    | —          | abc*+de/-  |

// **Operator Precedence and Associativity:**
// | Operator | Precedence | Associativity |
// |----------|------------|---------------|
// | +, -     | 1          | Left-to-Right |
// | *, /     | 2          | Left-to-Right |

// **Final Postfix Expression:** `abc*+de/-`

#include <stdio.h>
#include <stdlib.h>
char *convert(char *infix);     // Function to convert infix to postfix
int precedence(char x);
struct Stack            // Stack structure
{
    int size;
    int top;
    char *S;
};
void create(struct Stack *st)         // Function to create stack
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
char *convert(char *infix)           // Function to convert infix to postfix
{
    struct Stack st;
    create(&st);
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));       // +1 for null terminator
    int i = 0, j = 0;
    while (infix[i] != '\0')       // Scan infix expression
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9'))
        { 
            postfix[j++] = infix[i++];
        }
        else
        {
            while (st.top != -1 && precedence(stackTop(st)) >= precedence(infix[i]))     // Check precedence
            {
                postfix[j++] = pop(&st);
            }
            push(&st, infix[i++]);
        }
    }
    while (st.top != -1)             // Pop all operators from stack
    {
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    char *postfix = convert(infix);            // Convert to postfix
    printf("Postfix expression: %s\n", postfix);
    free(postfix);     //   Free allocated memory
    return 0;
}



