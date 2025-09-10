//New Year Chaos
//solved in c
#include <stdio.h>

void minimumBribes(int q[], int n) {
    int bribes = 0;

    for (int i = 0; i < n; i++) {
        // Check if too chaotic
        if (q[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }

        // Find starting point for inner loop
        int start;
        if (q[i] - 2 > 0) {
            start = q[i] - 2;
        } else {
            start = 0;
        }

        // Count bribes from start to i-1
        for (int j = start; j < i; j++) {
            if (q[j] > q[i]) {
                bribes++;
            }
        }
    }

    printf("%d\n", bribes);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int q[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &q[i]);
        }
        minimumBribes(q, n);
    }

    return 0;
}
