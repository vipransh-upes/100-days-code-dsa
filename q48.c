#include <stdio.h>
#include <stdlib.h>

// Tree node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue node
typedef struct QNode {
    Node* data;
    struct QNode* next;
} QNode;

QNode *front = NULL, *rear = NULL;

// Enqueue
void enqueue(Node* node) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->data = node;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

// Dequeue
Node* dequeue() {
    if (front == NULL) return NULL;

    QNode* temp = front;
    Node* node = temp->data;
    front = front->next;

    if (front == NULL) rear = NULL;

    free(temp);
    return node;
}

// Create node
Node* createNode(int val) {
    if (val == -1) return NULL;

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        Node* curr = dequeue();

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Count leaf nodes
int countLeaves(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    printf("%d", countLeaves(root));

    return 0;
}