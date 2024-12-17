#include <stdio.h>
#include <stdlib.h>

// Ð?nh nghia c?u trúc Node cho danh sách liên k?t don
struct Node {
    int data;
    struct Node* next;
};

// Hàm kh?i t?o danh sách r?ng
struct Node* initList() {
    return NULL;
}

// Hàm thêm ph?n t? vào d?u danh sách
struct Node* addHead(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Hàm thêm ph?n t? vào cu?i danh sách
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

// Hàm xóa ph?n t? ? d?u danh sách
struct Node* deleteHead(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Hàm xóa ph?n t? ? cu?i danh sách
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

// Hàm tìm ki?m ph?n t? trong danh sách
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

// Hàm hi?n th? các ph?n t? trong danh sách
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Hàm gi?i phóng b? nh?
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Kh?i t?o danh sách
    struct Node* head = initList();

    // Thêm ph?n t? vào d?u danh sách
    head = addHead(head, 3);
    head = addHead(head, 1);

    // Thêm ph?n t? vào cu?i danh sách
    head = addTail(head, 5);
    head = addTail(head, 7);

    // Hi?n th? danh sách
    printf("Danh sach: ");
    printList(head);

    // Xóa ph?n t? ? d?u danh sách
    head = deleteHead(head);
    printf("Danh sach sau khi xoa dau: ");
    printList(head);

    // Xóa ph?n t? ? cu?i danh sách
    head = deleteTail(head);
    printf("Danh sach sau khi xoa cuoi: ");
    printList(head);

    // Tìm ki?m ph?n t?
    if (searchElement(head, 5)) {
        printf("Tim thay phan tu 5 trong danh sach\n");
    } else {
        printf("Khong tim thay phan tu 5 trong danh sach\n");
    }

    // Gi?i phóng b? nh?
    freeList(head);

    return 0;
}
