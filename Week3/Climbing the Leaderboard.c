//Climbing the Leaderboard
//solved in c
#include <stdio.h>

void climbingLeaderboard(int ranked[], int n, int player[], int m) {
    int cleanRanked[n], size = 0;
    for (int i = 0; i < n; i++) {
        if (size == 0 || ranked[i] != cleanRanked[size - 1]) {
            cleanRanked[size++] = ranked[i];
        }
    }

    int r = size - 1;
    for (int i = 0; i < m; i++) {
        while (r >= 0 && player[i] >= cleanRanked[r]) r--;
        printf("%d\n", r + 2);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int ranked[n];
    for (int i = 0; i < n; i++) scanf("%d", &ranked[i]);

    int m;
    scanf("%d", &m);
    int player[m];
    for (int i = 0; i < m; i++) scanf("%d", &player[i]);

    climbingLeaderboard(ranked, n, player, m);
    return 0;
}
