/*Solve the following Laplace equation
∂2u/∂x2 + ∂2 u/∂y2 = 0
within 0 ≤ x ≤ 3, 0 ≤ y ≤ 3
For the rectangular plate given as:
*/
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
	float top, right, bottom, left;
	x = 4;
	y = 4;

	float Xprev[x], Xnew[x], error[x];
	int bye;
	float X[x];
	cout << "Top: ";
	cin >> top;
	cout << "Bottom: ";
	cin >> bottom;
	cout << "Right: ";
	cin >> right;
	cout << "Left: ";
	cin >> left;
	float A[x][y + 1] = {
		{-4, 1, 1, 0, -top - left},
		{1, -4, 0, 1, -top - right},
		{1, 0, -4, 1, -bottom - left},
		{0, 1, 1, -4, -bottom - right}};

	for (int j = 0; j < x; j++)
	{
		for (int i = j; i < x; i++)
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
			sendtoXprev(Xprev, Xnew, x);
			Xnew[i] = 0;
			for (int j = 0; j < x; j++)
			{
				if (i != j)
				{
					// cout<<Xnew[i]<<" + "<<A[i][j]<<" * "<<Xnew[j]<<endl;
					Xnew[i] = Xnew[i] + A[i][j] * Xnew[j];
				}
			}
			Xnew[i] = (A[i][x] - Xnew[i]) / A[i][i];
			// cout<<Xnew[i]<<endl;
		}

		bye = 1;
		for (int i = 0; i < x; i++)
		{
			error[i] = abs((Xnew[i] - Xprev[i]) / Xnew[i]);
			if (error[i] > 0.0005)
			{
				bye = 0;
			}
		}
	} while (bye != 1);

	for (int i = 0; i < x; i++)
	{
		cout << Xnew[i] << endl;
	}
	return 0;
}