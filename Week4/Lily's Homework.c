//Lily's Homework
//solved in c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

int cmpAsc(const void *a, const void *b) {
    return ((Pair*)a)->value - ((Pair*)b)->value;
}

int cmpDesc(const void *a, const void *b) {
    return ((Pair*)b)->value - ((Pair*)a)->value;
}

int countSwaps(Pair arr[], int n) {
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] || arr[i].index == i)
            continue;
        int cycle = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = 1;
            j = arr[j].index;
            cycle++;
        }
        if (cycle > 1)
            swaps += (cycle - 1);
    }
    return swaps;
}

int lilysHomework(int arr[], int n) {
    Pair arrAsc[n], arrDesc[n];
    for (int i = 0; i < n; i++) {
        arrAsc[i].value = arr[i];
        arrAsc[i].index = i;
        arrDesc[i].value = arr[i];
        arrDesc[i].index = i;
    }
    qsort(arrAsc, n, sizeof(Pair), cmpAsc);
    int posAsc[n];
    for (int i = 0; i < n; i++)
        posAsc[arrAsc[i].index] = i;
    for (int i = 0; i < n; i++)
        arrAsc[i].index = posAsc[i];
    qsort(arrDesc, n, sizeof(Pair), cmpDesc);
    int posDesc[n];
    for (int i = 0; i < n; i++)
        posDesc[arrDesc[i].index] = i;
    for (int i = 0; i < n; i++)
        arrDesc[i].index = posDesc[i];
    int swapsAsc = countSwaps(arrAsc, n);
    int swapsDesc = countSwaps(arrDesc, n);
    return (swapsAsc < swapsDesc) ? swapsAsc : swapsDesc;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", lilysHomework(arr, n));
    return 0;
}
