#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue for BFS
Node* queue[MAX];
int front = 0, rear = 0;

// Enqueue
void enqueue(Node* node) {
    if (node != NULL)
        queue[rear++] = node;
}

// Dequeue
Node* dequeue() {
    return queue[front++];
}

// Create node
Node* createNode(int val) {
    if (val == -1) return NULL;

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order
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

// Right view
void rightView(Node* root) {
    if (root == NULL) return;

    front = rear = 0;
    enqueue(root);

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            Node* curr = dequeue();

            // last node of level
            if (i == size - 1)
                printf("%d ", curr->data);

            if (curr->left) enqueue(curr->left);
            if (curr->right) enqueue(curr->right);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}