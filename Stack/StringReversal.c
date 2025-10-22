//string reversal using stack
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

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

void reverseString(char str[]) {
    Stack s;
    initStack(&s);

    // Push all characters into stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }

    // Pop all characters back (reversed)
    int i = 0;
    while (!isEmpty(&s)) {
        pop(&s, &str[i]);
        i++;
    }
    str[i] = '\0';
}

int main(void) {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline if any

    reverseString(str);

    printf("Reversed string: %s\n", str);
    return 0;
}
