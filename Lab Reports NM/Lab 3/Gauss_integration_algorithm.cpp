#include <iostream>
#include <cmath>

using namespace std;

// Function to define the integrand
double f(double x) {
    return exp(x); // Example function: e^x
}

// Function to calculate the Gauss quadrature approximation
double gaussQuad(double (*func)(double), double a, double b, int n) {
    double sum = 0.0;
    double xi, wi;

    // Coefficients and abscissas for Gauss quadrature
    double x[] = {-0.7745966692, 0.0, 0.7745966692};
    double w[] = {0.5555555556, 0.8888888889, 0.5555555556};

    for (int i = 0; i < n; ++i) {
        xi = ((b + a) / 2.0) + ((b - a) / 2.0) * x[i];
        wi = w[i] * ((b - a) / 2.0);
        sum += wi * func(xi);
    }

    return sum;
}

int main() {
    double a, b; // Lower and upper limits of integration
    int n; // Number of points for Gauss quadrature

    // Input lower and upper limits of integration
    cout << "Enter lower limit of integration: ";
    cin >> a;
    cout << "Enter upper limit of integration: ";
    cin >> b;

    // Input number of points for Gauss quadrature
    cout << "Enter the number of points for Gauss quadrature: ";
    cin >> n;

    // Calculate and output the result
    double result = gaussQuad(f, a, b, n);
    cout << "Result of integration: " << result << endl;

    return 0;
}
