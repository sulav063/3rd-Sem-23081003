#include <iostream>

using namespace std;

// Function to heapify a subtree rooted at node i
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; --i) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    // Input
    cout << "Enter the number of elements: ";
    int numElements;
    cin >> numElements;

    int arr[numElements];

    cout << "Enter the elements:\n";
    for (int i = 0; i < numElements; ++i) {
        cin >> arr[i];
    }

    // Sorting
    heapSort(arr, numElements);

    // Output
    cout << "Sorted array: ";
    for (int i = 0; i < numElements; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
