#include <stdio.h>

#define N 8

int isSafe(int board[N][N], int row, int col) {
    int i, j;

    for (i = 0; i < row; i++)
        if (board[i][col] == 1)
            return 0;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return 0;

    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return 0;

    return 1;
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf("* ");
        }
        printf("\n");
    }
}

void nQueensUtil(int board[N][N], int row) {
    if (row == N) {
        printBoard(board);
        printf("\n");
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            nQueensUtil(board, row + 1);

            board[row][col] = 0; // backtrack
        }
    }
}

void nQueens() {
    int board[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0} };

    nQueensUtil(board, 0);
}

int main() {
    nQueens();

    return 0;
}