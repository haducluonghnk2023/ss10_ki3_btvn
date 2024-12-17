#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

typedef struct {
    int array[MAX];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top >= MAX - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Ngan xep da day\n");
        return;
    }
    stack->array[++(stack->top)] = value;
    printf("Da them %d vao ngan xep\n", value);
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong\n");
        return;
    }
    printf("Da xoa %d khoi ngan xep\n", stack->array[(stack->top)--]);
}

void peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong\n");
        return;
    }
    printf("Phan tu tren cung cua ngan xep la: %d\n", stack->array[stack->top]);
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    peek(&stack); 

    pop(&stack);
    peek(&stack); 

    return 0;
}
