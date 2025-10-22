// Stack-based Recursive Factorial Implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

bool push(Stack* s, int value) {
    if (isFull(s)) return false;
    s->data[++(s->top)] = value;
    return true;
}

bool pop(Stack* s, int* value) {
    if (isEmpty(s)) return false;
    *value = s->data[(s->top)--];
    return true;
}

int factorial(int n) {
    if (n < 0) return -1;  // invalid input

    Stack s;
    initStack(&s);

    // Push all recursive calls
    while (n > 1) {
        push(&s, n);
        n--;
    }

    int result = 1;
    int val;

    // Simulate returning from recursion
    while (!isEmpty(&s)) {
        pop(&s, &val);
        result *= val;
    }

    return result;
}

int main(void) {
    int number;
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    int result = factorial(number);
    printf("Factorial of %d is %d\n", number, result);
    return 0;
}

