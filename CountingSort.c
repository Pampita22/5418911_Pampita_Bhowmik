//Counting Sort 1
//Solved in c
#include <stdio.h>

void countingSort(int arr[], int n, int freq[]) {
    
    for (int i = 0; i < 100; i++) {
        freq[i] = 0;
    }

    
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int freq[100];
    countingSort(arr, n, freq);

  
    for (int i = 0; i < 100; i++) {
        printf("%d ", freq[i]);
    }
    printf("\n");

    return 0;
}
