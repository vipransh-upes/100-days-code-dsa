#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    }
}

// Pop
void pop() {
    if (top >= 0) {
        top--;
    }
}

// Display
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0) printf(" ");
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // Push elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    // Pop m elements
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}