#include <stdlib.h>
#include "hanoi.h"

typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} Stack;

static Stack* createStack(int capacity) {
    Stack *stack = malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = malloc(capacity * sizeof(int));
    return stack;
}

static void push(Stack *stack, int disk) {
    stack->arr[++stack->top] = disk;
}

static int pop(Stack *stack) {
    return (stack->top == -1) ? -1 : stack->arr[stack->top--];
}

static int peek(Stack *stack) {
    return (stack->top == -1) ? -1 : stack->arr[stack->top];
}

static void move_disk(Stack *from, Stack *to) {
    int f = peek(from);
    int t = peek(to);

    if (f == -1) {
        pop(to);
        push(from, t);
    } else if (t == -1) {
        pop(from);
        push(to, f);
    } else if (f < t) {
        pop(from);
        push(to, f);
    } else {
        pop(to);
        push(from, t);
    }

    move_count++;
}

void hanoi_iterative(int n, char s, char a, char d) {
    Stack *src  = createStack(n);
    Stack *aux  = createStack(n);
    Stack *dest = createStack(n);

    for (int i = n; i >= 1; i--) push(src, i);

    int total_moves = (1 << n) - 1;

    if (n % 2 == 0) {
        char t = d;
        d = a;
        a = t;
    }

    for (int i = 1; i <= total_moves; i++) {
        if (i % 3 == 1)
            move_disk(src, dest);
        else if (i % 3 == 2)
            move_disk(src, aux);
        else
            move_disk(aux, dest);
    }

    free(src->arr); free(src);
    free(aux->arr); free(aux);
    free(dest->arr); free(dest);
}
