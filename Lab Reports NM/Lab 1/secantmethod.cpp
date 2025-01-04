/*Write a program to solve non-linear equations using the Secant method. Your program should 
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
//  #define f(x) (log(x)-3*pow(x,2)+5)
// #define f(x) (4*pow(x,3)- 2*x - 6)
// #define f(x) (x* sin(x) -1)
//  #define f(x) ( pow(e,x)-3*x)
#define f(x) (x - pow(e, x) + 2)
#define e 0.05

int main()
{
    int i = 0;

    double x0, x1, fx0, fx1, result, fresult, error = 0;

    cout << "Enter the value of x0:" << endl;
    cin >> x0;
    cout << "Enter the value of x1:" << endl;
    cin >> x1;

    cout << setw(10) << "No. of Iteration" << setw(15) << "(x0)" << setw(10)
        << "f(x0)" << setw(10) << "(x1)" << setw(10) << "f(x1)" << setw(15) 
        << "result" << setw(15) << "f(result)" << setw(10) << "error:" << endl;

    do
    
    {
        fx0 = f(x0);
        fx1 = f(x1);
        result = x1 - ((x1 - x0) * fx1) / (fx1 - fx0);
        fresult = f(result);
        error = abs((result - x1) / result);
        i++;

        cout << setw(15) << i << setw(15) << x0 << setw(10) << fx0 << setw(10) 
        << x1 << setw(10) << fx1 << setw(15) << result << setw(15) << fresult 
        << setw(10) << error << endl;

        x0 = x1;

        x1 = result;

    } while (error >= e);

    return 0;
}
