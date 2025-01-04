/*Write a program to solve non-linear equations using Newton’s method. Your program should
read an initial guess from keyboard and display the followings if the solution is obtained:
a. Estimated root of the equation
b. Functional value at calculated root
c. Required number of iterations
*/
#include <iostream>
#include <cmath>
#include <iomanip> // For setw function
using namespace std;

// #define f(x) sin(x) + pow(x, 2) + 5 * x - 9
// #define df(x) cos(x) + 2 * x + 5
// #define f(x) (pow(x,2)-5*x+6)
// #define df(x) (2*x-5)
// #define f(x) (pow(x,3)-6*pow(x,2)+11*x -6)
// #define df(x) (3*pow(x,2)-6*2*x+ 11)
// #define f(x) (pow(x,5) - 3*(pow(x,2)) - 100)
// #define df(x) (5*pow(x,4)-3*2*x)
#define f(x) (pow(x, 4) - 21 * pow(x, 3) + 149 * pow(x, 2) - 399 * x + 270)
#define df(x) (4 * pow(x, 3) - 21 * 3 * pow(x, 2) + 149 * 2 * x - 399)
#define e 0.05

int main()
{
    int i = 0;
    double xold, xnew, fxold, dfxold, result, error;

    cout << "Enter the value of x:" << endl;
    cin >> xold;

    cout << setw(15) << "No. of Iteration:" << setw(15) << "Xold" << setw(15) 
        << "f(Xold)" << setw(15) << "f'(Xold)" << setw(15) << "Xnew" << setw(15)
        << "Error:" << endl;

    do
    {
        fxold = f(xold);
        dfxold = df(xold);
        xnew = xold - (fxold / dfxold);

        if (xnew != 0)
        {
            error = fabs((xnew - xold) / xnew);
        }
        else
        {
            error = 0;
        }

        result = fxold;

        i++;

        cout << setw(15) << i << setw(15) << xold << setw(15) << fxold << setw(15)
        << dfxold << setw(15) << xnew << setw(15) << error << endl;
        xold = xnew;

    } while (fabs(result) >= e);

    return 0;
}
