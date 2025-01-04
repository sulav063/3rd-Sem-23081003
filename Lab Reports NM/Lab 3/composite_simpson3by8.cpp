#include <iostream>
#include <cmath>

using namespace std;

// Function to define the integrand
double f(double x) {
    return exp(x); // Example function: e^x
}

// Composite Simpson's 3/8 rule function
double compositeSimpsonsThreeEighth(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = f(a) + f(b); // Initialize sum with endpoints

    // Adding the value of the function at points
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) // Points that are multiples of 3
            sum += 2 * f(x);
        else // Other points
            sum += 3 * f(x);
    }

    return (3 * h / 8) * sum; // Final result
}

int main() {
    double a, b; // Lower and upper limits of integration
    int n; // Number of subintervals

    // Input lower and upper limits of integration
    cout << "Enter lower limit of integration: ";
    cin >> a;
    cout << "Enter upper limit of integration: ";
    cin >> b;

    // Input number of subintervals (must be multiple of 3)
    cout << "Enter the number of subintervals (must be multiple of 3): ";
    cin >> n;

    if (n % 3 != 0) {
        cout << "Number of subintervals must be multiple of 3." << endl;
        return 1;
    }

    // Calculate and output the result
    double result = compositeSimpsonsThreeEighth(a, b, n);
    cout << "Result of integration: " << result << endl;

    return 0;
}
