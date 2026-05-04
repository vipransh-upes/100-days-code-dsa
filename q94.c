#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Step 1: find max
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: count array
    int *count = (int*)calloc(max + 1, sizeof(int));

    // Step 3: frequency
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 4: prefix sum
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Step 5: build output (stable)
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 6: copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // Print result
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(count);
    return 0;
}