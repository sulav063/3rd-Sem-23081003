#include<iostream>
#include<cmath>

#define f(x) (1 / (x))

using namespace std;

int main() {
    float x0, xn, t[10][10], h, sm, sl, a;
    int i, k, c, r, m, p, q;
    
    cout << "Enter lower and upper limit: ";
    cin >> x0 >> xn;
    cout << "Enter p and q required T(p,q): ";
    cin >> p >> q;
    
    h = xn - x0;
    t[0][0] = h / 2 * ((f(x0)) + (f(xn)));
    
    for (i = 1; i <= p; i++) {
        sl = pow(2, i - 1);
        sm = 0;
        for (k = 1; k <= sl; k++) {
            a = x0 + (2 * k - 1) * h / pow(2, i);
            sm = sm + (f(a));
        }
        t[i][0] = t[i - 1][0] / 2 + sm * h / pow(2, i);
    }
    
    for (c = 1; c <= p; c++) {
        for (k = 1; k <= c && k <= q; k++) {
            m = c - k;
            t[m + k][k] = (pow(4, k) * t[m + k][k - 1] - t[m + k - 1][k - 1]) / (pow(4, k) - 1);
        }
    }
    
    cout << "Romberg estimate of integration = " << t[p][q] << endl;
    
    return 0;
}
