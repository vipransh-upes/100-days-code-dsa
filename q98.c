#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

// sort by start time
int cmp(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    // Step 1: sort
    qsort(arr, n, sizeof(Interval), cmp);

    // Result array
    Interval res[n];
    int k = 0;

    res[k++] = arr[0];

    // Step 2: merge
    for (int i = 1; i < n; i++) {
        if (arr[i].start <= res[k - 1].end) {
            // merge
            if (arr[i].end > res[k - 1].end)
                res[k - 1].end = arr[i].end;
        } else {
            res[k++] = arr[i];
        }
    }

    // Output
    for (int i = 0; i < k; i++) {
        printf("%d %d\n", res[i].start, res[i].end);
    }

    return 0;
}