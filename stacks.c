#include<stdio.h>
#include<stdlib.h>
#define MAX 12

typedef struct stack {
    int* data; // Pointer to the data array
    int size; // The size of the stack
    int top; // The index of the top of the stack
} stack;

void init(stack* s) {
    s->data = (int*)malloc(10 * sizeof(int));
    s->size = 10;
    s->top = -1;
}
void push(stack* s, int item) {
    if (s->top == s->size - 1) {
        s->data = (int*)realloc(s->data, 2 * s->size * sizeof(int));
        s->size *= 2;
    }
    s->top++;
    s->data[s->top] = item;
}
// to by s.
int pop(stack* s) {
    if (s->top == -1) {
        return -1;
    }
    int item = s->data[s->top];
    s->top--;
    return item;
}
// pointed to by s.
int eval(int* expr, int len) {
    stack s;
    init(&s);
    int i;

    int result = 0;
    for (i = 0; i < len; i++) {
        if (expr[i] == -1) {
            //addition
            result += pop(&s) + pop(&s);
        }
        if (expr[i] == -2) {
            //subtraction
            result -= pop(&s) + pop(&s);
        }
        else {
            push(&s, expr[i]);
        }
    }
    return result;
}

struct stack2 {
    int top; /* indicates index of top */
    int nodes[MAX];
};

// Attempts to push value onto the stack pointed to by s.
// If the stack is full 0 is returned and no action is taken.
// Otherwise, value is pushed onto the stack and 1 is returned.
int myPush(struct stack2* s, int value) {
    if (s == NULL) {
        return -1;
    }
    if (s->top == MAX - 1) {
        return 0;
    }
    s->top++;
    s->nodes[s->top] = value;
    return 1;
}

// Returns the value at the top of the stack. If the stack is
// empty, -1 is returned.
int peek(struct stack2* s) {
    if (s == NULL || s->top == -1) {
        return -1;
    }
    return s->nodes[s->top];
}

int main(void) {
    // int arr2[] = { 2, 5, -2, 10,15 ,-1, 123, -2, 102 };
    int arr[] = { 1, 2, -1, 5, 4, -2 };
    int len = sizeof(arr) / sizeof(int);
    printf("Result: %d", eval(arr, len));
    return 0;
}
