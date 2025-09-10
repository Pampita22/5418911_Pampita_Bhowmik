//Jesse and Cookies
//solved in c
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(int heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && heap[left] < heap[smallest]) smallest = left;
    if(right < n && heap[right] < heap[smallest]) smallest = right;
    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, n, smallest);
    }
}

void heapifyUp(int heap[], int i) {
    int parent = (i-1)/2;
    if(i > 0 && heap[i] < heap[parent]) {
        swap(&heap[i], &heap[parent]);
        heapifyUp(heap, parent);
    }
}

int extractMin(int heap[], int *n) {
    if(*n <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapifyDown(heap, *n, 0);
    return root;
}

void insertHeap(int heap[], int *n, int val) {
    heap[*n] = val;
    (*n)++;
    heapifyUp(heap, *n - 1);
}

int cookie(int k, int arr[], int n) {
    for(int i=(n/2)-1;i>=0;i--) heapifyDown(arr, n, i);
    int operations = 0;
    while(n > 1 && arr[0] < k) {
        int first = extractMin(arr, &n);
        int second = extractMin(arr, &n);
        int newCookie = first + 2*second;
        insertHeap(arr, &n, newCookie);
        operations++;
    }
    if(arr[0] >= k) return operations;
    return -1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    int result = cookie(k, arr, n);
    printf("%d\n", result);
    return 0;
}
