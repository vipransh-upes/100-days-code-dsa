#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

// Sort by start time
int cmp(const void *a, const void *b) {
    return ((Meeting*)a)->start - ((Meeting*)b)->start;
}

// Min heap functions
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l] < heap[smallest])
        smallest = l;
    if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    // Step 1: sort by start time
    qsort(arr, n, sizeof(Meeting), cmp);

    int heap[n]; // min heap of end times
    int size = 0;

    for (int i = 0; i < n; i++) {
        // if room free
        if (size > 0 && arr[i].start >= heap[0]) {
            heap[0] = arr[i].end;
            heapifyDown(heap, size, 0);
        } else {
            heap[size] = arr[i].end;
            heapifyUp(heap, size);
            size++;
        }
    }

    printf("%d", size);
    return 0;
}