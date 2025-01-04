#include <iostream>
using namespace std;

// Define the structure for a node in the linear search tree
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Define the LinearSearchTree class
class LinearSearchTree {
private:
    Node* head;

public:
    // Constructor
    LinearSearchTree() {
        head = NULL;
    }

    // Public method to insert a value into the linear search tree
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Public method to print the linear search tree elements
    void printTree() {
        cout << "Linear Search Tree: ";
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Public method to search for a value in the linear search tree
    bool search(int value) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    LinearSearchTree lst;
    int numValues;
    int value;

    cout << "How many numbers do you want to add to the linear search tree? ";
    cin >> numValues;

    cout << "Enter " << numValues << " numbers: ";
    for (int i = 0; i < numValues; ++i) {
        cin >> value;
        lst.insert(value);
    }

    lst.printTree();

    int searchValue;
    cout << "Enter a value to search for in the linear search tree: ";
    cin >> searchValue;

    if (lst.search(searchValue)) {
        cout << "Value found in the linear search tree." << endl;
    } else {
        cout << "Value not found in the linear search tree." << endl;
    }

    return 0;
}
