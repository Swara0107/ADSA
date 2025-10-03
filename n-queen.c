#include <stdio.h>
#include <stdbool.h>

#define MAX 20  // Maximum board size (can be increased if needed)

// Function prototypes
bool SolveNQ(int board[MAX][MAX], int row, int n);
bool IsSafe(int board[MAX][MAX], int row, int col, int n);
void PrintBoard(int board[MAX][MAX], int n);

// Main procedure to start the N-Queens solution
void NQueens(int n) {
    int board[MAX][MAX] = {0};  // Initialize the chessboard with all 0s

    // Try to solve the problem starting from row 0
    if (!SolveNQ(board, 0, n)) {
        // If solution does not exist
        printf("No solution exists\n");
    }
}

// Recursive function to place queens row by row
bool SolveNQ(int board[MAX][MAX], int row, int n) {
    // Base case: If all queens are placed successfully
    if (row == n) {
        PrintBoard(board, n);  // Print the current valid board
        return true;           // Return true to indicate success
    }

    bool res = false;  // Flag to check if any valid position was found

    // Try placing queen in all columns one by one
    for (int col = 0; col < n; col++) {
        // Check if it's safe to place the queen at board[row][col]
        if (IsSafe(board, row, col, n)) {
            board[row][col] = 1;  // Place the queen

            // Recursively place queen in the next row
            res = SolveNQ(board, row + 1, n) || res;

            // Backtrack: Remove queen from board[row][col]
            board[row][col] = 0;
        }
    }

    return res;  // Return whether any solution was found in this branch
}

// Function to check if it's safe to place a queen at board[row][col]
bool IsSafe(int board[MAX][MAX], int row, int col, int n) {
    // Check the same column in previous rows
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;  // Position is safe
}

// Function to print the current board configuration
void PrintBoard(int board[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Print 1 for queen, 0 for empty
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");  // Extra line between solutions
}

// Main function
int main() {
    int n;

    // Input number of queens
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    // Check for maximum allowed size
    if (n > MAX) {
        printf("Maximum supported size is %d\n", MAX);
        return 1;
    }

    // Call the NQueens function
    NQueens(n);

    return 0;
}
