#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 10;

void swapRows(double matrix[MAX_SIZE][MAX_SIZE], int row1, int row2, int n) {
    for (int i = 0; i < n * 2; ++i) {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

void gaussJordan(double matrix[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        if (matrix[i][i] == 0) {
            cout << "Inverse doesn't exist. Zero on diagonal." << endl;
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (i != j) {
                double ratio = matrix[j][i] / matrix[i][i];
                for (int k = 0; k < n * 2; ++k) {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        double divisor = matrix[i][i];
        for (int j = 0; j < n * 2; ++j) {
            matrix[i][j] /= divisor;
        }
    }
}

void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int n) {
    cout << "Inverse Matrix is:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = n; j < n * 2; ++j) {
            cout << fixed << setprecision(3) << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    double matrix[MAX_SIZE][MAX_SIZE * 2];

    cout << "Enter order of matrix: ";
    cin >> n;

    cout << "Enter coefficients of Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
        for (int j = n; j < n * 2; ++j) {
            matrix[i][j] = (i == (j - n)) ? 1 : 0; // Augmenting with identity matrix
        }
    }

    gaussJordan(matrix, n);
    printMatrix(matrix, n);

    return 0;
}
