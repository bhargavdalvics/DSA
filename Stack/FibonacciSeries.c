//fibonacci series
#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct {
    int n;
    int state;
    int a, b;
} Frame;

typedef struct {
    Frame data[MAX];
    int top;
} Stack;

void initStack(Stack* s) { s->top = -1; }
bool isEmpty(Stack* s) { return s->top == -1; }
bool isFull(Stack* s) { return s->top == MAX - 1; }

bool push(Stack* s, Frame f) {
    if (isFull(s)) return false;
    s->data[++(s->top)] = f;
    return true;
}

bool pop(Stack* s, Frame* f) {
    if (isEmpty(s)) return false;
    *f = s->data[(s->top)--];
    return true;
}

int fib(int n) {
    Stack s;
    initStack(&s);

    Frame f = {n, 0, 0, 0};
    push(&s, f);

    int result = 0;

    while (!isEmpty(&s)) {
        pop(&s, &f);

        if (f.n == 0) result = 0;
        else if (f.n == 1) result = 1;
        else if (f.state == 0) {
            // First call (like fib(n-1))
            f.state = 1;
            push(&s, f);

            Frame f1 = {f.n - 1, 0, 0, 0};
            push(&s, f1);
        }
        else if (f.state == 1) {
            f.a = result;
            f.state = 2;
            push(&s, f);

            Frame f2 = {f.n - 2, 0, 0, 0};
            push(&s, f2);
        }
        else {
            result = f.a + result;
        }
    }

    return result;
}

int main(void) {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");

    return 0;
}
