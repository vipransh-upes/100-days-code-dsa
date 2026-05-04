#include <stdio.h>
#include <stdlib.h>

// Node for linked list bucket
typedef struct Node {
    float data;
    struct Node* next;
} Node;

// Insert at head
void insert(Node** head, float val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = *head;
    *head = temp;
}

// Insertion sort on linked list
Node* insertionSort(Node* head) {
    Node* sorted = NULL;

    while (head) {
        Node* curr = head;
        head = head->next;

        if (sorted == NULL || curr->data < sorted->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < curr->data)
                temp = temp->next;

            curr->next = temp->next;
            temp->next = curr;
        }
    }
    return sorted;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    // Step 1: create buckets
    Node* buckets[n];
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Step 2: distribute
    for (int i = 0; i < n; i++) {
        int idx = (int)(n * arr[i]);
        insert(&buckets[idx], arr[i]);
    }

    // Step 3: sort each bucket
    for (int i = 0; i < n; i++)
        buckets[i] = insertionSort(buckets[i]);

    // Step 4: concatenate
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* temp = buckets[i];
        while (temp) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }

    // Output
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}