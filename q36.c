#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int val) {
    if ((rear + 1) % MAX == front) {
        // Queue full (not needed for this problem usually)
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = val;
}

// Dequeue
void dequeue() {
    if (front == -1) return;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if (front == -1) return;

    int i = front;

    while (1) {
        printf("%d", queue[i]);
        if (i == rear) break;
        printf(" ");
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    // Dequeue m elements
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // Display result
    display();

    return 0;
}