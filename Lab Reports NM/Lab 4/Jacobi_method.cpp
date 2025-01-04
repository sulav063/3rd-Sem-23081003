#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
void sendtoXprev(float Xprev[], float Xnew[], int x)
{
    for (int i = 0; i < x; i++)
    {
        Xprev[i] = Xnew[i];
    }
}
int main()
{
    int x, y;
    cout << "How many equations do you have? ";
    cin >> x;
    cout << "How many variables do you have? ";
    cin >> y;

    float A[x][y + 1];
    float Xprev[x], Xnew[x], error[x];
    int bye;
    float X[x];

    for (int i = 0; i < x; i++)
    {
        cout << "For 1st equation: " << endl;
        Xnew[i] = 0;
        for (int j = 0; j <= y; j++)
        {
            if (j == y)
            {
                cout << "Enter the value of constant : ";
            }
            else
            {
                cout << "Enter the value of x" << i + 1 << " : ";
            }
            cin >> A[i][j];
        }
        cout << endl;
    }

    for (int j = 0; j < x; j++)
    {
        for (int i = j; i < x - 1; i++)
        {
            if (abs(A[i][j]) < abs(A[i + 1][j]))
            {
                for (int k = 0; k <= x; k++)
                {
                    int temp = A[i][k];
                    A[i][k] = A[i + 1][k];
                    A[i + 1][k] = temp;
                }
            }
        }
    }

    do
    {
        for (int i = 0; i < x; i++)
        {
            Xnew[i] = 0;
            for (int j = 0; j < x; j++)
            {
                if (i != j)
                {
                    cout << Xnew[i] << " + " << A[i][j] << " * " << Xprev[j] << endl;
                    Xnew[i] = Xnew[i] + A[i][j] * Xprev[j];
                }
            }
            Xnew[i] = (A[i][x] - Xnew[i]) / A[i][i];
            cout << Xnew[i] << endl;
        }

        bye = 1;
        for (int i = 0; i < x; i++)
        {
            error[i] = abs((Xnew[i] - Xprev[i]) / Xnew[i]);
            if (error[i] > 0.05)
            {
                bye = 0;
            }
        }
        sendtoXprev(Xprev, Xnew, x);
    } while (bye != 1);

    for (int i = 0; i < x; i++)
    {
        cout << Xnew[i] << endl;
    }
    return 0;
}