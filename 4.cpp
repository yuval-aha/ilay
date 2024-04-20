#include <iostream>
using namespace std;

bool is_peak(int a[][5], int rows, int cols, int i, int j) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {

        return false;
    }

    int height = a[i][j];

    if (i > 0 && a[i-1][j] >= height) {
        return false;
    }
    if (j > 0 && a[i][j-1] >= height) {
        return false;
    }
    if (i < rows - 1 && a[i+1][j] >= height) {
        return false;
    }
    if (j < cols - 1 && a[i][j+1] >= height) {
        return false;
    }
    if (i > 0 && j > 0 && a[i-1][j-1] >= height) {
        return false;
    }
    if (i > 0 && j < cols - 1 && a[i-1][j+1] >= height) {
        return false;
    }
    if (i < rows - 1 && j > 0 && a[i+1][j-1] >= height) {
        return false;
    }
    if (i < rows - 1 && j < cols - 1 && a[i+1][j+1] >= height) {
        return false;
    }

    return true;
}


int main() {
    int matrix[5][5] = {
        {26, 16, 4, 1, 10},
        {12, 14, 5, 12, 5},
        {25, 3, 8, 2, 6},
        {10, 12, 5, 4, 12},
        {18, 22, 5, 6, 8}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int row, col;
    cout << "Enter row and column: ";
    cin >> row >> col;

    if (is_peak(matrix, 5, 5, row, col)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}