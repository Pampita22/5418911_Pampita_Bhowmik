//Tower Breakers
//solved in c
#include <stdio.h>

int towerBreakers(int n, int m) {
    if (m == 1) return 2;        // No moves possible -> Player 2 wins
    if (n % 2 == 0) return 2;    // Even number of towers -> Player 2 wins
    return 1;                    // Odd number of towers -> Player 1 wins
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", towerBreakers(n, m));
    }
    return 0;
}
