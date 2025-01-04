#include <iostream>

using namespace std;

int main() {
    int count, t, limit;
    float temp, error, a, sum = 0;
    float matrix[10][10], y[10], allowed_error;

    cout << "\nEnter the Total Number of Equations:\t";
    cin >> limit;

    cout << "Enter Allowed Error:\t";
    cin >> allowed_error;
    cout << "\nEnter the Co-Efficients\n";

    for (count = 1; count <= limit; count++) {
        for (t = 1; t <= limit + 1; t++) {
            cout << " Matrix[" << count << "][" << t << "] = ";
            cin >> matrix[count][t];
        }
    }

    for (count = 1; count <= limit; count++) {
        y[count] = 0;
    }

    do {
        a = 0;
        for (count = 1; count <= limit; count++) {
            sum = 0;
            for (t = 1; t <= limit; t++) {
                if (t != count) {
                    sum += matrix[count][t] * y[t];
                }
            }
            temp = (matrix[count][limit + 1] - sum) / matrix[count][count];
            error = temp - y[count];
            if (error < 0) {
                error = -error;
            }
            if (error > a) {
                a = error;
            }
            y[count] = temp;
            cout << "\nY[" << count << "]=\t" << y[count];
        }
        cout << "\n";
    } while (a >= allowed_error);

    cout << "\n\nSolution\n\n";

    for (count = 1; count <= limit; count++) {
        cout << " \nY[" << count << "]:\t" << y[count];
    }

    return 0;
}
