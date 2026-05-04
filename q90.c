#include <stdio.h>

// check if possible within maxTime
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int current = 0;

    for (int i = 0; i < n; i++) {
        if (current + boards[i] <= maxTime) {
            current += boards[i];
        } else {
            painters++;
            current = boards[i];
        }

        if (painters > k)
            return 0;
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if (boards[i] > maxVal)
            maxVal = boards[i];
    }

    int low = maxVal;
    int high = sum;
    int ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1; // try smaller max time
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);
    return 0;
}
