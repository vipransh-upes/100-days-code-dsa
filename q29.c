#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate list
Node* rotateRight(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    Node* temp = head;
    int n = 1;

    // Find length
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Make circular
    temp->next = head;

    // Reduce k
    k = k % n;

    // Find new tail (n-k steps)
    int steps = n - k;
    Node* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // New head
    Node* newHead = newTail->next;

    // Break circle
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, x, k;

    scanf("%d", &n);

    Node *head = NULL, *tail = NULL;

    // Input list
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        Node* newNode = createNode(x);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}