#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long low = 0, high = n, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid <= n / mid) {  // avoids overflow of mid*mid
            ans = mid;         // mid is a valid candidate
            low = mid + 1;     // try to find a larger one
        } else {
            high = mid - 1;
        }
    }

    printf("%lld", ans);
    return 0;
}