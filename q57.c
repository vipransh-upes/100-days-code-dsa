#include <stdio.h>
#include <stdlib.h>

// Tree node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue node (for building tree)
typedef struct QNode {
    Node* data;
    struct QNode* next;
} QNode;

QNode *front = NULL, *rear = NULL;

// Enqueue
void enqueue(Node* node) {
    QNode* t = (QNode*)malloc(sizeof(QNode));
    t->data = node;
    t->next = NULL;
    if (rear == NULL) front = rear = t;
    else { rear->next = t; rear = t; }
}

// Dequeue
Node* dequeue() {
    if (front == NULL) return NULL;
    QNode* t = front;
    Node* node = t->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(t);
    return node;
}

// Create node
Node* createNode(int val) {
    if (val == -1) return NULL;
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// Build tree (level-order)
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;
    while (i < n) {
        Node* cur = dequeue();

        if (i < n && arr[i] != -1) {
            cur->left = createNode(arr[i]);
            enqueue(cur->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            cur->right = createNode(arr[i]);
            enqueue(cur->right);
        }
        i++;
    }
    return root;
}

// Mirror tree
Node* mirror(Node* root) {
    if (root == NULL) return NULL;

    // Mirror subtrees
    mirror(root->left);
    mirror(root->right);

    // Swap children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    mirror(root);

    inorder(root);

    return 0;
}