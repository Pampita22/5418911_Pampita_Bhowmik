//Lego Blocks
//solved in c

#include <stdio.h>
#define MOD 1000000007

long long modPow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    int n[1000], m[1000], maxM = 0;
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &n[i], &m[i]);
        if (m[i] > maxM) maxM = m[i];
    }
    long long f[maxM+1];
    f[0] = 1;
    for (int w = 1; w <= maxM; w++) {
        f[w] = 0;
        for (int k = 1; k <= 4; k++) {
            if (w-k >= 0) f[w] = (f[w] + f[w-k]) % MOD;
        }
    }
    for (int t = 0; t < T; t++) {
        int N = n[t], M = m[t];
        long long g[M+1], h[M+1];
        for (int w = 0; w <= M; w++) g[w] = modPow(f[w], N);
        h[0] = 1;
        for (int w = 1; w <= M; w++) {
            long long bad = 0;
            for (int i = 1; i < w; i++) bad = (bad + h[i] * g[w-i]) % MOD;
            h[w] = (g[w] - bad + MOD) % MOD;
        }
        printf("%lld\n", h[M]);
    }
    return 0;
}
