#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* initList() {
    return NULL;
}

struct Node* addHead(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

struct Node* addTail(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node* deleteHead(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteTail(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return deleteHead(head);
    }

    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    struct Node* temp = current->next;
    current->next = NULL;
    free(temp);
    return head;
}

int searchElement(struct Node* head, int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
h
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = initList();
    head = addHead(head, 3);
    head = addHead(head, 1);
    head = addTail(head, 5);
    head = addTail(head, 7);
    printf("Danh sach: ");
    printList(head);
    head = deleteHead(head);
    printf("Danh sach sau khi xoa dau: ");
    printList(head);
    head = deleteTail(head);
    printf("Danh sach sau khi xoa cuoi: ");
    printList(head);
    if (searchElement(head, 5)) {
        printf("Tim thay phan tu 5 trong danh sach\n");
    } else {
        printf("Khong tim thay phan tu 5 trong danh sach\n");
    }
    freeList(head);

    return 0;
}
