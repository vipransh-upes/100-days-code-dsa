#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long prefix_sum = 0;
    long long count = 0;

    // Using simple large array as hash (assuming constraints are reasonable)
    // For general case, better to use unordered_map in C++
    
    long long freq[200001] = {0};  
    int offset = 100000;   // to handle negative sums
    
    freq[offset] = 1;  // prefix sum = 0 initially

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(freq[prefix_sum + offset] > 0)
            count += freq[prefix_sum + offset];

        freq[prefix_sum + offset]++;
    }

    printf("%lld\n", count);

    return 0;
}