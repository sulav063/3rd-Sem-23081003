/*Write a program to implement least square approximation for Non-linear data:*/

#include <iostream>
#include <cmath>
using namespace std;

float Calculate(float a, float b, float x) {
    return (a * exp(b * x));
}

int main() {
    int size;
    cout << "Enter size of data: ";
    cin >> size;

    // Use dynamic allocation for arrays
    float *x = new float[size];
    float *y = new float[size];
    float xtotal = 0, ytotal = 0, x2 = 0, xy = 0;
    float b, a;

    for (int i = 0; i < size; i++) {
        cout << "Enter value for x" << i << ": ";
        cin >> x[i];
        cout << "Enter value for y" << i << ": ";
        cin >> y[i];

        if (y[i] <= 0) {
            cout << "Error: y values must be greater than 0 for logarithmic transformation.\n";
            delete[] x;
            delete[] y;
            return 1; // Exit the program if y[i] is not positive
        }

        // Apply transformation
        float logY = log(y[i]);
        xtotal += x[i];
        x2 += x[i] * x[i];
        ytotal += logY;
        xy += (x[i] * logY);
    }

    b = (float)(size * xy - xtotal * ytotal) / (size * x2 - xtotal * xtotal);
    a = exp((ytotal / size) - b * (xtotal / size));

    cout << "y = " << a << " * e^(" << b << "x)" << endl;

    // Predicting a new y value for a given x
    int val;
    cout << "Enter x to predict y: ";
    cin >> val;
    cout << "y = " << Calculate(a, b, val) << endl;

    // Clean up
    delete[] x;
    delete[] y;

    return 0;
}