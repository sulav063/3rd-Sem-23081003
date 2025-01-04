#include<iostream>

using namespace std;

// Define the integrand function
double f(double x, double y) {
    return x * y; // Example function: xy
}

// Trapezoidal rule for double integration
double doubleIntegralTrapezoidal(double a, double b, double c, double d, int m, int n) {
    double hx = (b - a) / m;
    double hy = (d - c) / n;
    double sum = 0.0;

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            double x = a + i * hx;
            double y = c + j * hy;
            double weight = 1.0;
            
            // Apply weight based on position
            if (i == 0 || i == m) {
                if (j == 0 || j == n) weight = 0.25; // Corner points
                else weight = 0.5; // Boundary points
            } else {
                if (j == 0 || j == n) weight = 0.5; // Boundary points
            }

            sum += weight * f(x, y);
        }
    }

    return sum * hx * hy;
}

int main() {
    double a, b, c, d; // Limits of integration
    int m, n; // Number of intervals

    // Input limits of integration
    cout << "Enter lower limit of integration in x direction: ";
    cin >> a;
    cout << "Enter upper limit of integration in x direction: ";
    cin >> b;
    cout << "Enter lower limit of integration in y direction: ";
    cin >> c;
    cout << "Enter upper limit of integration in y direction: ";
    cin >> d;

    // Input number of intervals
    cout << "Enter the number of intervals in x direction: ";
    cin >> m;
    cout << "Enter the number of intervals in y direction: ";
    cin >> n;

    // Calculate and output the result
    double result = doubleIntegralTrapezoidal(a, b, c, d, m, n);
    cout << "Result of double integration: " << result << endl;

    return 0;
}
