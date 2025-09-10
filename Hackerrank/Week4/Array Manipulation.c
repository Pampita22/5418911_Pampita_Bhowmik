//Array Manipulation
//solved in c
#include <stdio.h>
#define MAX 10000005
long arr[MAX];

long mani(int n, int m, int querie[m][3]) {
    for (int i = 0; i <= n+1; i++) arr[i] = 0; 

    
    for (int i = 0; i < m; i++) {
        int a = querie[i][0];
        int b = querie[i][1];
        long k = querie[i][2];
        arr[a] += k;
        arr[b+1] -= k;
    }

    
    long max = 0, curr = 0;
    for (int i = 1; i <= n; i++) {
        curr += arr[i];
        if (curr > max) max = curr;
    }
    return max;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int querie[m][3];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &querie[i][0], &querie[i][1], &querie[i][2]);
    }
    long result = mani(n, m, querie);
    printf("%ld\n", result);
    return 0;
}
