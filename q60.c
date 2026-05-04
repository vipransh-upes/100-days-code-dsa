#include <stdio.h>

int isMinHeap(int arr[], int n) {
    // Check Complete Binary Tree (CBT)
    int nullFound = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            nullFound = 1;
        } else {
            if (nullFound) return 0; // non-null after null → not complete
        }
    }

    // Check Heap Property
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (arr[i] == -1) continue;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] != -1 && arr[i] > arr[left])
            return 0;

        if (right < n && arr[right] != -1 && arr[i] > arr[right])
            return 0;
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (isMinHeap(arr, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}