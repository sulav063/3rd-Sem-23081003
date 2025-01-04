#include <iostream>

using namespace std;

void shellSort(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < n; i += 1) {
            // add arr[i] to the elements that have been gap sorted
            // save arr[i] in temp and make a hole at position i
            int temp = arr[i];
            
            // shift earlier gap-sorted elements up until the correct location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            // put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

int main() {
    cout << "Enter the number of elements: ";
    int numElements;
    cin >> numElements;

    int arr[numElements];

    cout << "Enter the elements:\n";
    for (int i = 0; i < numElements; ++i) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    for (int i = 0; i < numElements; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    shellSort(arr, numElements);
    
    cout << "Sorted array: ";
    for (int i = 0; i < numElements; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

