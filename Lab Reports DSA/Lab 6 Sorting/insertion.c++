#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    cout << "Enter the number of elements: ";
    int numElements;
    cin >> numElements;

    int* arr = new int[numElements];

    cout << "Enter the elements:\n";
    for (int i = 0; i < numElements; ++i) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    for (int i = 0; i < numElements; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    insertionSort(arr, numElements);
    
    cout << "Sorted array: ";
    for (int i = 0; i < numElements; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free dynamically allocated memory
    delete[] arr;
    
    return 0;
}

