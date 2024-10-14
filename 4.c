#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[1000];

void ShiftTableComputation(char p[]) {
    int m, i, j;
    m = strlen(p);
    for (i = 0; i < 1000; i++) {
        table[i] = m;
    }
    for (j = 0; j <= m - 2; j++) {
        table[p[j]] = m - 1 - j;
    }
}

void HPoolStringMatching(char p[], char t[]) {
    int m, n, i, k;
    ShiftTableComputation(p);
    m = strlen(p);
    n = strlen(t);
    i = m - 1;
    int found = 0;
    while (i <= n - 1) {
        k = 0;
        while ((k <= m - 1) && t[i - k] == p[m - 1 - k]) {
            k++;
        }
        if (k == m) {
            printf("Pattern found at position %d\n", i - m + 2);
            found = 1;
            i += table[t[i]]; // Move past the current match
        } else {
            i += table[t[i]];
        }
    }
    if (!found) {
        printf("Pattern not found\n");
    }
}

int main() {
    char str[100], ptr[100];
    printf("Enter the text: ");
    scanf("%s", str);
    printf("Enter the pattern: ");
    scanf("%s", ptr);
    HPoolStringMatching(ptr, str);
    return 0;
}