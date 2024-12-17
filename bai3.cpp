#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Kích thu?c t?i da c?a ngan x?p

// C?u trúc ngan x?p
typedef struct {
    int array[MAX];
    int top;
} Stack;

// Kh?i t?o ngan x?p r?ng
void initStack(Stack* stack) {
    stack->top = -1;
}

// Ki?m tra ngan x?p r?ng
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Ki?m tra ngan x?p d?y
int isFull(Stack* stack) {
    return stack->top >= MAX - 1;
}

// Thêm ph?n t? vào ngan x?p (push)
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Ngan xep da day\n");
        return;
    }
    stack->array[++(stack->top)] = value;
    printf("Da them %d vao ngan xep\n", value);
}

// Xóa ph?n t? kh?i ngan x?p (pop)
void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong\n");
        return;
    }
    printf("Da xoa %d khoi ngan xep\n", stack->array[(stack->top)--]);
}

// L?y ph?n t? trên cùng c?a ngan x?p (peek)
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
