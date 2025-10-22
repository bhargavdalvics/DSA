//palindrome using stack
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>   // for tolower()

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

// Stack functions
void initStack(Stack *s) { s->top = -1; }
bool isFull(Stack *s) { return s->top == MAX - 1; }
bool isEmpty(Stack *s) { return s->top == -1; }

bool push(Stack *s, char ch) {
    if (isFull(s)) return false;
    s->data[++(s->top)] = ch;
    return true;
}

bool pop(Stack *s, char *ch) {
    if (isEmpty(s)) return false;
    *ch = s->data[(s->top)--];
    return true;
}

bool isPalindrome(char str[]) {
    Stack s;
    initStack(&s);

    int len = strlen(str);

    // Push all characters (ignoring spaces and case)
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i]))  // only alphabets
            push(&s, tolower(str[i]));
    }

    // Compare popped characters with string (forward reading)
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            char ch;
            pop(&s, &ch);
            if (tolower(str[i]) != ch)
                return false;
        }
    }

    return true;
}

int main(void) {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline

    if (isPalindrome(str))
        printf("✅ The string is a palindrome.\n");
    else
        printf("❌ The string is not a palindrome.\n");

    return 0;
}
