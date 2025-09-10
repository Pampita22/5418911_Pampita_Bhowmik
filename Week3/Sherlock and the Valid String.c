//Sherlock and the Valid String
//solved in c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

const char* isValid(char* s) {
    int freq[26] = {0};
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }
    int f[26], m = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            f[m++] = freq[i];
        }
    }
    qsort(f, m, sizeof(int), cmp);
    if (f[0] == f[m-1]) return "YES";
    if (f[0] == 1 && f[1] == f[m-1]) return "YES";
    if ((f[m-1] - f[m-2] == 1) && f[0] == f[m-2]) return "YES";
    return "NO";
}

int main() {
    char s[100001];
    scanf("%s", s);
    printf("%s\n", isValid(s));
    return 0;
}
