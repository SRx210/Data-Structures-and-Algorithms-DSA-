#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the length of the Longest Common Subsequence (LCS)
int longestCommonSubsequence(char *X, char *Y, int m, int n, char *lcs) {
    int LCS[m + 1][n + 1];

    // Build the LCS array in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    // Construct LCS from LCS array
    int index = LCS[m][n];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        else
            j--;
    }

    return LCS[m][n];
}

int main() {
    char text1[MAX_LEN], text2[MAX_LEN];
    char lcs[MAX_LEN];

    // Input first text
    printf("Enter first text: ");
    fgets(text1, MAX_LEN, stdin);
    text1[strcspn(text1, "\n")] = '\0'; // Remove newline character

    // Input second text
    printf("Enter second text: ");
    fgets(text2, MAX_LEN, stdin);
    text2[strcspn(text2, "\n")] = '\0'; // Remove newline character

    // Calculate length of LCS and length of each text
    int m = strlen(text1);
    int n = strlen(text2);
    int lcs_length = longestCommonSubsequence(text1, text2, m, n, lcs);

    printf("One of the common subsequences and the longest subsquences: %s\n", lcs);

    return 0;
}
