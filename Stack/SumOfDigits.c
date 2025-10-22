//Sum of digits
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }
bool isFull(Stack *s) { return s->top == MAX - 1; }
bool isEmpty(Stack *s) { return s->top == -1; }

bool push(Stack *s, int value) {
    if (isFull(s)) return false;
    s->data[++(s->top)] = value;
    return true;
}

bool pop(Stack *s, int *value) {
    if (isEmpty(s)) return false;
    *value = s->data[(s->top)--];
    return true;
}

int sumOfDigits(int num) {
    Stack s;
    initStack(&s);

    if (num < 0)
        num = -num;

    // Push digits into stack
    while (num != 0) {
        push(&s, num % 10);
        num /= 10;
    }

    // Pop and sum
    int sum = 0, digit;
    while (!isEmpty(&s)) {
        pop(&s, &digit);
        sum += digit;
    }

    return sum;
}

int main(void) {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int result = sumOfDigits(num);
    printf("Sum of digits = %d\n", result);

    return 0;
}
