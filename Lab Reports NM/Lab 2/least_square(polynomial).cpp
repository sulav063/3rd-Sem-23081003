#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, n;
    cout.precision(4);
    cout.setf(ios::fixed);

    cout << "Enter the number of data pairs to be entered: ";
    cin >> N;

    vector<double> x(N), y(N);
    cout << "Enter the x-axis values: ";
    for (int i = 0; i < N; i++)
        cin >> x[i];

    cout << "Enter the y-axis values: ";
    for (int i = 0; i < N; i++)
        cin >> y[i];

    cout << "What degree of Polynomial do you want to use for the fit? ";
    cin >> n;

    vector<double> X(2 * n + 1, 0);
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < N; j++)
            X[i] += pow(x[j], i);
    }

    vector<vector<double>> B(n + 1, vector<double>(n + 2));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            B[i][j] = X[i + j];
    }

    vector<double> Y(n + 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < N; j++)
            Y[i] += pow(x[j], i) * y[j];
        B[i][n + 1] = Y[i];
    }

    n = n + 1;

    cout << "\nThe Normal(Augmented Matrix) is as follows:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++)
            cout << B[i][j] << setw(16);
        cout << "\n";
    }

    // Gaussian Elimination
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            double t = B[k][i] / B[i][i];
            for (int j = 0; j <= n; j++)
                B[k][j] -= t * B[i][j];
        }
    }

    vector<double> a(n);
    for (int i = n - 1; i >= 0; i--) {
        a[i] = B[i][n];
        for (int j = 0; j < n; j++) {
            if (j != i)
                a[i] -= B[i][j] * a[j];
        }
        a[i] /= B[i][i];
    }

    cout << "\nThe values of the coefficients are as follows:\n";
    for (int i = 0; i < n; i++)
        cout << "x^" << i << "=" << a[i] << endl;

    cout << "\nHence the fitted Polynomial is given by:\ny=";
    for (int i = 0; i < n; i++)
        cout << " + (" << a[i] << ")" << "x^" << i;
    cout << "\n";

    return 0;
}
