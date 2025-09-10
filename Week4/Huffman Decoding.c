//Tree: Huffman Decoding
//solved in c
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
typedef struct node {
    int freq;
    char data;
    struct node *left, *right;
} node;

int isLeaf(node* n) {
    return (n->left == NULL && n->right == NULL);
}

void decode_huff(node* root, char* s) {
    node* curr = root;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if (isLeaf(curr)) {
            printf("%c", curr->data);
            curr = root; // reset to root for next symbol
        }
    }
}
