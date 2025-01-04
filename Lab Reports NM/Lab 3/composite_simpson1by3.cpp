#include <iostream>
#include <cmath>

using namespace std;

// Function to define the integrand
double f(double x) {
    return exp(x); // Example function: e^x
}

// Composite Simpson's 1/3 rule function
double compositeSimpsonsOneThird(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = f(a) + f(b); // Initialize sum with endpoints

    // Adding the value of the function at even and odd points
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) // Even points
            sum += 2 * f(x);
        else // Odd points
            sum += 4 * f(x);
    }

    return (h / 3) * sum; // Final result
}

int main() {
    double a, b; // Lower and upper limits of integration
    int n; // Number of subintervals

    // Input lower and upper limits of integration
    cout << "Enter lower limit of integration: ";
    cin >> a;
    cout << "Enter upper limit of integration: ";
    cin >> b;

    // Input number of subintervals (must be even)
    cout << "Enter the number of subintervals (must be even): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Number of subintervals must be even." << endl;
        return 1;
    }

    // Calculate and output the result
    double result = compositeSimpsonsOneThird(a, b, n);
    cout << "Result of integration: " << result << endl;

    return 0;
}
