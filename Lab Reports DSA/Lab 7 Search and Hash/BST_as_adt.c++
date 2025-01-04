#include <iostream>
using namespace std;

// Define the structure for a node in the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left =NULL;
        right =NULL;
    }
};

// Define the BinarySearchTree class
class BinarySearchTree {
private:
    Node* root;

    // Helper function to insert a node recursively
    Node* insertRecursive(Node* root, int value) {
        if (root ==NULL) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    // Helper function for in-order traversal to print values
    void inorderTraversal(Node* root) {
        if (root !=NULL) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

public:
    // Constructor
    BinarySearchTree() {
        root =NULL;
    }

    // Public method to insert a value into the BST
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Public method to print BST elements in sorted order
    void printSortedArray() {
        cout << "Sorted Array: ";
        inorderTraversal(root);
        cout << endl;
    }

    // Public method to search for a value in the BST
    bool search(int value) {
        Node* current = root;
        while (current !=NULL) {
            if (current->data == value) {
                return true;
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
};

int main() {
    BinarySearchTree bst;
    int numValues;
    int value;

    cout << "How many numbers do you want to add to the binary search tree? ";
    cin >> numValues;

    cout << "Enter " << numValues << " numbers: ";
    for (int i = 0; i < numValues; ++i) {
        cin >> value;
        bst.insert(value);
    }

    bst.printSortedArray();

    int searchValue;
    cout << "Enter a value to search for in the binary search tree: ";
    cin >> searchValue;

    if (bst.search(searchValue)) {
        cout << "Value found in the binary search tree." << endl;
    } else {
        cout << "Value not found in the binary search tree." << endl;
    }

    return 0;
}
