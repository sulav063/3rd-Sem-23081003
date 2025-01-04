/*Write a program to to calculate an approximate value of y when x = 0.4 given that
∂y/∂x = x + y and y(0) = 1.
With h=0.1 and h=0.2
Using the following algorithms.
1.Euler’s algorithm*/
#include <iostream>
#include <cmath>
using namespace std;

float f(float x, float y)
{
    return x + y;
}

void Eulers(float x, float Z[], float Y[], float h)
{
    int i = 1;
    for (i = 1; x > Z[i - 1]; i++)
    {
        Z[i] = Z[i - 1] + h;
        Y[i] = Y[i - 1] + h * f(Z[i - 1], Y[i - 1]);
    }
    cout << "When h= " << h << " y(" << Z[i - 1] << ") = " << Y[i - 1] << endl;
}

int main()
{
    float h;
    float x = 0.4;
    h = 0.1;
    int n = (x - 0) / h;
    float Z[n + 1], Y[n + 1];
    Z[0] = 0;
    Y[0] = 1;

    Eulers(x, Z, Y, h);
    h = 0.2;
    Eulers(x, Z, Y, h);

    return 0;
}
