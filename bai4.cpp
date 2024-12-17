#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue q) {
    return (q.front == -1);
}

int isFull(Queue q) {
    return ((q.rear + 1) % MAX_SIZE == q.front); 
}

void enqueue(Queue* q, int value) {
    if (isFull(*q)) {
        printf("Hang doi day!\n");
    } else {
        if (isEmpty(*q)) {
            q->front = 0; 
        }
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->data[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    if (isEmpty(*q)) {
        printf("Hang doi rong!\n");
        return -1;
    } else {
        int value = q->data[q->front];
        if (q->front == q->rear) { 
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX_SIZE;
        }
        return value;
    }
}

int peek(Queue q) {
    if (isEmpty(q)) {
        printf("Hang doi rong!\n");
        return -1;
    } else {
        return q.data[q.front];
    }
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Phan tu dau hang doi: %d\n", peek(q));

    printf("Xoa phan tu khoi hang doi: %d\n", dequeue(&q));
    printf("Phan tu dau hang doi: %d\n", peek(q));

    return 0;
}
