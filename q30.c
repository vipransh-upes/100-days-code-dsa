#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int c, int e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
Node* insert(Node* head, int c, int e) {
    Node* newNode = createNode(c, e);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print polynomial
void printPolynomial(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        // Print coefficient
        printf("%d", temp->coeff);

        // Print variable part
        if (temp->exp > 1)
            printf("x^%d", temp->exp);
        else if (temp->exp == 1)
            printf("x");

        // Print + if not last node
        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

// Main
int main() {
    int n, c, e;
    Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        head = insert(head, c, e);
    }

    printPolynomial(head);

    return 0;
}