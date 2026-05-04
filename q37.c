#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert
void insert(int x) {
    if (size < MAX) {
        pq[size++] = x;
    }
}

// Find index of minimum element
int findMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete (remove min)
void deleteMin() {
    int idx = findMinIndex();

    if (idx == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[idx]);

    // Shift elements
    for (int i = idx; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Peek (show min)
void peek() {
    int idx = findMinIndex();

    if (idx == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[idx]);
    }
}

int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') { // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') { // delete
            deleteMin();
        }
        else if (op[0] == 'p') { // peek
            peek();
        }
    }

    return 0;
}