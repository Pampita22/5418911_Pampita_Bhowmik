//Simple Text Editor
//solved in c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Q 100005
#define MAX_LEN 1000005

typedef struct {
    int type;   // 1 = append, 2 = delete
    int len;    // number of characters
    char *data; // only for delete
} Operation;

char text[MAX_LEN];
int length = 0;

Operation history[MAX_Q];
int top = -1;

void push_append(int len) {
    if (top + 1 >= MAX_Q) return; // safety
    top++;
    history[top].type = 1;
    history[top].len = len;
    history[top].data = NULL;
}

void push_delete(const char *deleted, int len) {
    if (top + 1 >= MAX_Q) return; // safety
    top++;
    history[top].type = 2;
    history[top].len = len;
    history[top].data = (char *)malloc(len + 1);
    strcpy(history[top].data, deleted);
}

Operation pop() {
    Operation empty = {0, 0, NULL};
    if (top < 0) return empty; // nothing to undo
    return history[top--];
}

int main() {
    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {  // append
            char s[10005];
            scanf("%s", s);
            int len = strlen(s);

            if (length + len >= MAX_LEN) len = MAX_LEN - length - 1; // prevent overflow

            push_append(len);

            memcpy(text + length, s, len);
            length += len;
            text[length] = '\0';

        } else if (type == 2) {  // delete
            int k;
            scanf("%d", &k);

            if (k > length) k = length; // safety

            char *deleted = (char *)malloc(k + 1);
            strncpy(deleted, text + length - k, k);
            deleted[k] = '\0';

            push_delete(deleted, k);
            free(deleted);

            length -= k;
            text[length] = '\0';

        } else if (type == 3) {  // print
            int k;
            scanf("%d", &k);

            if (k >= 1 && k <= length) {
                printf("%c\n", text[k - 1]);
            }

        } else if (type == 4) {  // undo
            Operation last = pop();

            if (last.type == 1) {
                length -= last.len;
                if (length < 0) length = 0;
                text[length] = '\0';
            } else if (last.type == 2) {
                int len = last.len;
                if (length + len >= MAX_LEN) len = MAX_LEN - length - 1;
                memcpy(text + length, last.data, len);
                length += len;
                text[length] = '\0';
                free(last.data);
            }
        }
    }
    return 0;
}
