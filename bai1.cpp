#include <stdio.h>
#include <stdlib.h>

// �?nh nghia c?u tr�c Node cho danh s�ch li�n k?t don
struct Node {
    int data;
    struct Node* next;
};

// H�m kh?i t?o danh s�ch r?ng
struct Node* initList() {
    return NULL;
}

// H�m th�m ph?n t? v�o d?u danh s�ch
struct Node* addHead(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// H�m th�m ph?n t? v�o cu?i danh s�ch
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

// H�m x�a ph?n t? ? d?u danh s�ch
struct Node* deleteHead(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// H�m x�a ph?n t? ? cu?i danh s�ch
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

// H�m t�m ki?m ph?n t? trong danh s�ch
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

// H�m hi?n th? c�c ph?n t? trong danh s�ch
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// H�m gi?i ph�ng b? nh?
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Kh?i t?o danh s�ch
    struct Node* head = initList();

    // Th�m ph?n t? v�o d?u danh s�ch
    head = addHead(head, 3);
    head = addHead(head, 1);

    // Th�m ph?n t? v�o cu?i danh s�ch
    head = addTail(head, 5);
    head = addTail(head, 7);

    // Hi?n th? danh s�ch
    printf("Danh sach: ");
    printList(head);

    // X�a ph?n t? ? d?u danh s�ch
    head = deleteHead(head);
    printf("Danh sach sau khi xoa dau: ");
    printList(head);

    // X�a ph?n t? ? cu?i danh s�ch
    head = deleteTail(head);
    printf("Danh sach sau khi xoa cuoi: ");
    printList(head);

    // T�m ki?m ph?n t?
    if (searchElement(head, 5)) {
        printf("Tim thay phan tu 5 trong danh sach\n");
    } else {
        printf("Khong tim thay phan tu 5 trong danh sach\n");
    }

    // Gi?i ph�ng b? nh?
    freeList(head);

    return 0;
}
