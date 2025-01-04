#include <iostream>
#include <cmath>

using namespace std;

// Define the integrand function
double f(double x) {
    return exp(x); // Example function: e^x
}

// Composite Trapezoidal rule function
double compositeTrapezoidal(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = 0.5 * (f(a) + f(b)); // Initialize sum with endpoints

    // Adding the value of the function at intermediate points
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum; // Final result
}

int main() {
    double a, b; // Lower and upper limits of integration
    int n; // Number of subintervals

    // Input lower and upper limits of integration
    cout << "Enter lower limit of integration: ";
    cin >> a;
    cout << "Enter upper limit of integration: ";
    cin >> b;

    // Input number of subintervals
    cout << "Enter the number of subintervals: ";
    cin >> n;

    // Calculate and output the result
    double result = compositeTrapezoidal(a, b, n);
    cout << "Result of integration: " << result << endl;

    return 0;
}
