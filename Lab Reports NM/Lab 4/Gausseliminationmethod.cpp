#include <iostream>
using namespace std;

int main()
{
    int i, j, k, n;
    float a[10][11], b, x[10]; // Increase the size to accommodate the augmented matrix
    
    cout << "Enter the size of matrix: ";
    cin >> n;
    
    cout << "\nEnter the elements of augmented matrix (row-wise):\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= (n + 1); j++) // Adjust the loop to consider the augmented column
        {
            cout << "A[" << i << ", " << j << " ]=";
            cin >> a[i][j];
        }
    }

    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= n; i++)
        {
            if (i != j)
            {
                b = a[i][j] / a[j][j];
                for (k = 1; k <= (n + 1); k++) // Adjust the loop to consider the augmented column
                {
                    a[i][k] = a[i][k] - b * a[j][k];
                }
            }
        }
    }
    
    cout << "\nThe solution is:\n";
    for (i = 1; i <= n; i++)
    {
        x[i] = a[i][n + 1] / a[i][i];
        cout << "x" << i << "=" << x[i] << " ";
    }
    return 0;
}
