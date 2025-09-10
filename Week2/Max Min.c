//Max Min
//solved in c
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int unfair(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), compare); 

    int min = arr[k - 1] - arr[0];
    for (int i = 1; i <= n - k; i++) {
        int diff = arr[i + k - 1] - arr[i];
        if (diff < min) {
            min = diff;
        }
    }
    return min;
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = unfair(arr, n, k);
    printf("%d\n", result);

    return 0;
}
