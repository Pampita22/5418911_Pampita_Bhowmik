//Queries with Fixed Length
//solved in c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void precompute_min_of_max(int *a, int n, int *ans) {
    int *prev = (int*)malloc(n * sizeof(int));
    int *next = (int*)malloc(n * sizeof(int));
    int *stack = (int*)malloc(n * sizeof(int));
    int top;

    top = -1;
    for (int i = 0; i < n; i++) {
        while (top >= 0 && a[stack[top]] <= a[i]) top--;
        prev[i] = (top >= 0) ? stack[top] : -1;
        stack[++top] = i;
    }

    top = -1;
    for (int i = n - 1; i >= 0; i--) {
        while (top >= 0 && a[stack[top]] < a[i]) top--;
        next[i] = (top >= 0) ? stack[top] : n;
        stack[++top] = i;
    }

    for (int k = 0; k <= n; k++) ans[k] = INT_MAX;
    for (int i = 0; i < n; i++) {
        int len = next[i] - prev[i] - 1;
        if (a[i] < ans[len]) ans[len] = a[i];
    }

    for (int k = n - 1; k >= 1; k--) {
        if (ans[k] > ans[k + 1]) ans[k] = ans[k + 1];
    }

    free(prev);
    free(next);
    free(stack);
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int *ans = (int*)malloc((n + 1) * sizeof(int));
    precompute_min_of_max(a, n, ans);

    while (q--) {
        int d;
        scanf("%d", &d);
        if (d < 1) d = 1;
        if (d > n) d = n;
        printf("%d\n", ans[d]);
    }

    free(a);
    free(ans);
    return 0;
}
