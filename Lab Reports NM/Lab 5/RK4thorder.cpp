// 3.RK 4th order method
#include <iostream>
#include <cmath>
using namespace std;

float f(float x, float y)
{
    return x + y;
}

void RK(float x, float Z[], float Y[], float h, float m1, float m2, float m3, float m4)
{
    int i = 1;
    for (i = 1; x > Z[i - 1]; i++)
    {
        m1 = f(Z[i - 1], Y[i - 1]);
        m2 = f(Z[i - 1] + (0.5 * h), Y[i - 1] + (h * m1 * 0.5));
        m3 = f(Z[i - 1] + (0.5 * h), Y[i - 1] + (h * m2 * 0.5));
        m4 = f(Z[i - 1] + h, Y[i - 1] + h * m3);
        Z[i] = Z[i - 1] + h;
        Y[i] = Y[i - 1] + h / 6 * (m1 + 2 * m2 + 2 * m3 + m4);
    }
    cout << "When h= " << h << " y(" << Z[i - 1] << ") = " << Y[i - 1] << endl;
}

int main()
{
    float h, m1, m2, m3, m4;
    float x = 0.4;
    h = 0.1;
    int n = (x - 0) / h;
    float Z[n + 1], Y[n + 1];
    Z[0] = 0;
    Y[0] = 1;

    RK(x, Z, Y, h, m1, m2, m3, m4);
    h = 0.2;
    RK(x, Z, Y, h, m1, m2, m3, m4);

    return 0;
}