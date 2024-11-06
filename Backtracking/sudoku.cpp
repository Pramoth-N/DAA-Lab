#include <bits/stdc++.h>
using namespace std;

#define N 9

bool isValidInput(const vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] < 0 || grid[i][j] > 9) {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }
    
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    
    return true;
}

bool solveSudoku(vector<vector<int>>& grid, int row, int col) {
    if (row == N - 1 && col == N) {
        return true;
    }
    if (col == N) {
        row++;
        col = 0;
    }
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }
    
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    
    return false;
}

void printGrid(const vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> grid(N, vector<int>(N));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    if (!isValidInput(grid)) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    if (solveSudoku(grid, 0, 0)) {
        printGrid(grid);
    } else {
        cout << "No solution exists" << endl;
    }
    
    return 0;
}