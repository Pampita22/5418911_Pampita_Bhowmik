//Grid Challenge
//solved in c
#include <stdio.h>
#include <string.h>

void sortRow(char row[]) {
    int len = strlen(row);
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (row[j] > row[j + 1]) { 
                char temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char grid[101][101];

        
        for (int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
            sortRow(grid[i]); 
        }

       
        int ok = 1; 
        for (int col = 0; col < strlen(grid[0]); col++) {
            for (int row = 0; row < n - 1; row++) {
                if (grid[row][col] > grid[row + 1][col]) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
        }

       
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
