//Dynamic Array 
//Solved in c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Array;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    Array *arr = (Array *)malloc(n * sizeof(Array));
    for (int i = 0; i < n; i++) {
        arr[i].data = NULL;
        arr[i].size = 0;
        arr[i].capacity = 0;
    }

    int lastAnswer = 0;

    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            if (arr[idx].size == arr[idx].capacity) {
                arr[idx].capacity = arr[idx].capacity == 0 ? 2 : arr[idx].capacity * 2;
                arr[idx].data = (int *)realloc(arr[idx].data, arr[idx].capacity * sizeof(int));
            }
            arr[idx].data[arr[idx].size++] = y;
        } else {
            lastAnswer = arr[idx].data[y % arr[idx].size];
            printf("%d\n", lastAnswer);
        }
    }

    for (int i = 0; i < n; i++) free(arr[i].data);
    free(arr);

    return 0;
}
