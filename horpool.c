#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
int table[SIZE];

void shiftable(char p[25]) {
    int m = strlen(p);
    for (int i = 0; i < SIZE; i++)
        table[i] = m;
    for (int i = 0; i < m - 1; i++)
        table[p[i]] = m - i - 1;
}

int horpool(char T[100], char p[25]) {
    int m = strlen(p);
    int n = strlen(T);
    int i = m - 1;

    while (i < n) {
        int k = 0;
        while (k < m && p[m - 1 - k] == T[i - k])
            k++;
        if (k == m)
            return i - m + 1;
        else
            i += table[T[i]];
    }
    return -1;
}

int main() {
    char text[100], pattern[25];
    int res;

    printf("Read text: ");
    scanf("%s", text);

    printf("Read pattern: ");
    scanf("%s", pattern);

    shiftable(pattern);
    res = horpool(text, pattern);

    if (res == -1)
        printf("Pattern not found\n");
    else
        printf("Pattern found at position %d\n", res);

    return 0;
}
