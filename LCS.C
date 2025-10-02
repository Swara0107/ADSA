#include <stdio.h>
#include <string.h>
// Function to find maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}
// Function to find LCS length
int LCS(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m + 1][n + 1];
    // Fill dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n]; // Length of LCS
}
int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    int length = LCS(str1, str2);
    printf("Length of Longest Common Subsequence: %d\n", length);
    return 0;
}
