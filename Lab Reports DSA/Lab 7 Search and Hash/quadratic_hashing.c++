#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *data = new int[size];
    cout << "Enter " << size << " integers for the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> data[i];
    }

    int *hash = new int[10]{0}; // Initialize hash table with zeros

    for (int i = 0; i < size; ++i)
    {
        int temp;
        temp = data[i];

        for (int j = 0; j < 100; ++j, ++temp)
        {
            int index = temp % 10;
            if (hash[index] == 0)
            {
                hash[index] = data[i];
                break;
            }
            else // Quadratic probing
            {
                index = (index + j * j) % 10;
                if (hash[index] == 0)
                {
                    hash[index] = data[i];
                    break;
                }
            }
        }
    }

    cout << "Resulting hash table: ";
    bool isFirst = true;
    for (int i = 0; i < 10; ++i)
    {
        if (hash[i] != 0)
        {
            if (!isFirst) cout << ", ";
            cout << hash[i];
            isFirst = false;
        }
    }

    delete[] data;
    delete[] hash;

    return 0;
}
