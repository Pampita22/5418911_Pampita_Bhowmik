//XOR Strings 2
//solved in c
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


char* strings_xor(char* s, char* t, int n) {
    char* res = (char*)malloc(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i])
            res[i] = '0';   // changed from '1'
        else
            res[i] = '1';   // changed from '0'
    }
    res[n] = '\0';
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char s[100], t[100];
    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(s);
    char* result = strings_xor(s, t, n);
    printf("%s\n", result);
    free(result);

    return 0;
}
