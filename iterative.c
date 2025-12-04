#include <stdlib.h>
#include "hanoi.h"

/**
 * Stack structure to represent a peg in the Tower of Hanoi.
 * 
 * arr      : dynamically allocated array to hold disk values
 * top      : index of the top element in the stack (-1 if empty)
 * capacity : maximum number of disks the stack can hold
 */
typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} Stack;

/**
 * Creates a new stack with a given capacity.
 * 
 * @param capacity Maximum number of disks the stack can hold
 * @return Pointer to the newly created Stack
 */
static Stack* createStack(int capacity) {
    Stack *stack = malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;                 // Initialize as empty stack
    stack->arr = malloc(capacity * sizeof(int)); // Allocate array for disks
    return stack;
}

/**
 * Pushes a disk onto the stack.
 * 
 * @param stack Pointer to the Stack
 * @param disk  Disk value to push
 */
static void push(Stack *stack, int disk) {
    stack->arr[++stack->top] = disk;
}

/**
 * Pops the top disk from the stack.
 * 
 * @param stack Pointer to the Stack
 * @return Disk value popped, or -1 if stack is empty
 */
static int pop(Stack *stack) {
    return (stack->top == -1) ? -1 : stack->arr[stack->top--];
}

/**
 * Peeks at the top disk of the stack without removing it.
 * 
 * @param stack Pointer to the Stack
 * @return Disk value at the top, or -1 if stack is empty
 */
static int peek(Stack *stack) {
    return (stack->top == -1) ? -1 : stack->arr[stack->top];
}

/**
 * Moves the top disk between two stacks according to Hanoi rules.
 * 
 * @param from Pointer to source stack
 * @param to   Pointer to destination stack
 * 
 * Logic:
 * - If the source is empty, move top from destination to source
 * - If the destination is empty, move top from source to destination
 * - If top of source < top of destination, move from source to destination
 * - Else move from destination to source
 */
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

    // Increment global move counter
    move_count++;
}

/**
 * Solves the Tower of Hanoi problem iteratively.
 * 
 * @param n Number of disks
 * @param s Character representing the source peg
 * @param a Character representing the auxiliary peg
 * @param d Character representing the destination peg
 * 
 * Algorithm:
 * 1. Initialize three stacks for the pegs
 * 2. Push all disks onto the source stack (largest at bottom)
 * 3. Compute total number of moves (2^n - 1)
 * 4. Swap auxiliary and destination pegs if n is even
 * 5. Perform moves iteratively in a fixed sequence determined by modulo 3
 * 6. Free allocated memory for the stacks
 */
void hanoi_iterative(int n, char s, char a, char d) {
    Stack *src  = createStack(n);
    Stack *aux  = createStack(n);
    Stack *dest = createStack(n);

    // Push disks onto source peg in descending order
    for (int i = n; i >= 1; i--) push(src, i);

    int total_moves = (1 << n) - 1; // 2^n - 1 moves

    // Swap auxiliary and destination pegs if number of disks is even
    if (n % 2 == 0) {
        char t = d;
        d = a;
        a = t;
    }

    // Iteratively move disks according to fixed modulo 3 pattern
    for (int i = 1; i <= total_moves; i++) {
        if (i % 3 == 1)
            move_disk(src, dest);
        else if (i % 3 == 2)
            move_disk(src, aux);
        else
            move_disk(aux, dest);
    }

    // Free memory allocated for stacks
    free(src->arr); free(src);
    free(aux->arr); free(aux);
    free(dest->arr); free(dest);
}
