#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue element (node + horizontal distance)
typedef struct Pair {
    Node* node;
    int hd;
} Pair;

// Simple queue
Pair queue[MAX];
int front = 0, rear = 0;

// Enqueue
void enqueue(Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

// Dequeue
Pair dequeue() {
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

// Build tree from level order
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = createNode(arr[0]);
    enqueue(root, 0);

    int i = 1;

    while (i < n) {
        Pair p = dequeue();
        Node* curr = p.node;

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left, 0);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right, 0);
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    // Reset queue for traversal
    front = rear = 0;

    // Map: HD range from -1000 to +1000
    int map[2001][MAX], count[2001] = {0};
    int offset = 1000;

    int minHD = 1000, maxHD = -1000;

    // BFS traversal
    enqueue(root, 0);

    while (front < rear) {
        Pair p = dequeue();
        Node* node = p.node;
        int hd = p.hd;

        if (node == NULL) continue;

        int idx = hd + offset;

        map[idx][count[idx]++] = node->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        enqueue(node->left, hd - 1);
        enqueue(node->right, hd + 1);
    }

    // Print vertical order
    for (int hd = minHD; hd <= maxHD; hd++) {
        int idx = hd + offset;
        for (int i = 0; i < count[idx]; i++) {
            printf("%d ", map[idx][i]);
        }
        printf("\n");
    }

    return 0;
}