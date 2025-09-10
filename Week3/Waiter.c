//Waiter
//solved in c
#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void generatePrimes(int primes[], int q) {
    int count = 0, num = 2;
    while (count < q) {
        if (isPrime(num)) {
            primes[count++] = num;
        }
        num++;
    }
}

void waiter(int plates[], int n, int q) {
    int primes[q];
    generatePrimes(primes, q);

    int A[n], B[n];
    int stack[n], top = -1;

    for (int i = 0; i < n; i++) {
        stack[++top] = plates[i];
    }

    for (int i = 0; i < q; i++) {
        int topA = -1, topB = -1;

        while (top >= 0) {
            int plate = stack[top--];
            if (plate % primes[i] == 0)
                B[++topB] = plate;
            else
                A[++topA] = plate;
        }

        while (topB >= 0) {
            printf("%d\n", B[topB--]);
        }

        top = -1;
        for (int k = 0; k <= topA; k++) {
            stack[++top] = A[k];
        }
    }

    while (top >= 0) {
        printf("%d\n", stack[top--]);
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int plates[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &plates[i]);
    }

    waiter(plates, n, q);
    return 0;
}
