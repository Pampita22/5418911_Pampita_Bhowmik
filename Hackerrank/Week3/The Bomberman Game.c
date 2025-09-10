//The Bomberman Game
//solved in c
#include <stdio.h>

#define MAX 210

int r, c;
char grid[MAX][MAX];
char firstExp[MAX][MAX];
char secondExp[MAX][MAX];

void fill_full_into(char dest[MAX][MAX]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            dest[i][j] = 'O';
}

void explode(char src[MAX][MAX], char dest[MAX][MAX]) {
    fill_full_into(dest);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (src[i][j] == 'O') {
                dest[i][j] = '.';
                if (i > 0)     dest[i-1][j] = '.';
                if (i < r - 1) dest[i+1][j] = '.';
                if (j > 0)     dest[i][j-1] = '.';
                if (j < c - 1) dest[i][j+1] = '.';
            }
        }
    }
}

int main(void) {
    long long n;
    if (scanf("%d %d %lld", &r, &c, &n) != 3) return 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf(" %c", &grid[i][j]);

    if (n <= 1) {
    } else if (n % 2 == 0) {
        fill_full_into(grid);
    } else {
        explode(grid, firstExp);
        explode(firstExp, secondExp);
        if (n % 4 == 3) {
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    grid[i][j] = firstExp[i][j];
        } else {
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    grid[i][j] = secondExp[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            putchar(grid[i][j]);
        putchar('\n');
    }
    return 0;
}
