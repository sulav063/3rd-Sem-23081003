#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n; // Number of data points
    float x, xp, h, term, sum = 0;
    int index; // Index for the divided difference
    float y[100][100]; // Divided difference table

    cout << "Enter the number of data points: ";
    cin >> n;

    // Input x-values and corresponding function values
    // Fill the divided difference table

    cout << "Enter the value of x for which you want to find the derivative: ";
    cin >> xp;  

    // Calculate the derivative using forward differences
    h = x - x; // Assuming constant step size
    index = 0; // Choose the appropriate index

    for (int i = 1; i < n - index; i++) {
        term = pow(y[index][i], i) / i;
        sum += (i % 2 == 0) ? -term : term;
    }

    float first_derivative = sum / h;

    // Display the result
    cout << "First derivative at x = " << xp << " is " << first_derivative << endl;

    return 0;
}
