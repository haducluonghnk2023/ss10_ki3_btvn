#include <stdio.h>
#include <stdlib.h>

// Ð?nh nghia c?u trúc Node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Hàm t?o m?t node m?i
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Hàm thêm node vào cây nh? phân
struct Node* insert(struct Node* node, int data) {
    // N?u cây r?ng, tr? v? node m?i
    if (node == NULL) {
        return newNode(data);
    }

    // Ngu?c l?i, d? quy xu?ng cây con trái ho?c ph?i
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    // Tr? v? node chua du?c thay d?i
    return node;
}

// Hàm duy?t cây theo th? t? tru?c (PreOrder)
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Hàm duy?t cây theo th? t? gi?a (InOrder)
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Hàm duy?t cây theo th? t? sau (PostOrder)
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Hàm tìm ki?m m?t ph?n t? trong cây
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nMENU\n");
        printf("1. Them node\n");
        printf("2. Duyet PreOrder\n");
        printf("3. Duyet InOrder\n");
        printf("4. Duyet PostOrder\n");
        printf("5. Tim kiem\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                preOrder(root);
                printf("\n");
                break;
            case 3:
                inOrder(root);
                printf("\n");
                break;
            case 4:
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &data);
                if (search(root, data) != NULL) {
                    printf("Tim thay %d trong cay\n", data);
                } else {
                    printf("Khong tim thay %d trong cay\n", data);
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}
