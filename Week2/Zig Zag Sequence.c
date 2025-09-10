//Zig Zag Sequence
//Solved in c
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void findZigZagSequence(int a[], int n) {
    int temp;
    // Step 1: sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // FIX 1: Correct middle index
    int mid = (n - 1) / 2;
    temp = a[mid];
    a[mid] = a[n - 1];
    a[n - 1] = temp;

    // FIX 2: Reverse from mid+1 to n-2
    int st = mid + 1;
    int ed = n - 2;
    while (st <= ed) {
        temp = a[st];
        a[st] = a[ed];
        a[ed] = temp;
        st++;
        // FIX 3: decrement end pointer
        ed--;
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        findZigZagSequence(a, n);
    }
    return 0;
}
