#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 2

typedef struct {
    int *elements;
    int top;
    int capacity;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->elements = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    stack->top = -1;
    stack->capacity = INITIAL_CAPACITY;
    return stack;
}

void push(Stack* stack, int element) {
    if (stack->top == stack->capacity - 1) {
        int newCapacity = stack->capacity * 2;
        int* newElements = (int*)malloc(newCapacity * sizeof(int));
        for (int i = 0; i < stack->capacity; i++) {
            newElements[i] = stack->elements[i];
        }
        free(stack->elements);
        stack->elements = newElements;
        stack->capacity = newCapacity;
    }
    stack->elements[++stack->top] = element;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->elements[stack->top--];
}


void printStack(Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d\n ", stack->elements[i]);
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printStack(stack); 
    pop(stack);
    printStack(stack);
    return 0;
}