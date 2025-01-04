#include <iostream>
#include <stack>

using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Function to insert a new node at the end of the linked list
    void push(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to pop the linked list
    void pop() {
        if (head == NULL) {
            cout << "Linked List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to delete a number from the linked list
    void deleteNumber(int value) {
        Node* temp = head;
        Node* prev = NULL;

        // If the value is found at head
        if (temp != NULL && temp->data == value) {
            head = temp->next;
            delete temp;
            cout << "Value " << value << " deleted from the linked list." << endl;
            return;
        }

        // Search for the value to be deleted
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        // If the value is not present in the linked list
        if (temp == NULL) {
            cout << "Value " << value << " not found in the linked list." << endl;
            return;
        }

        // Unlink the node from linked list
        prev->next = temp->next;
        delete temp;
        cout << "Value " << value << " deleted from the linked list." << endl;
    }

    // Function to convert a stack to a linked list
    void stackToLinkedList(stack<int>& s) {
        while (!s.empty()) {
            push(s.top());
            s.pop();
        }
    }
};

int main() {
    stack<int> s;
    LinkedList list;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert element into the linked list\n";
        cout << "2. Delete a number from the linked list\n";
        cout << "3. pop the linked list\n";
        cout << "4. Convert stack to linked list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.push(value);
                cout << "Value inserted into the linked list." << endl;
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                list.deleteNumber(value);
                break;
            case 3:
                cout << "Linked List elements: ";
                list.pop();
                break;
            case 4:
                cout << "Enter values for the stack (enter -1 to stop):\n";
                while (true) {
                    cin >> value;
                    if (value == -1) break;
                    s.push(value);
                }
                list.stackToLinkedList(s);
                cout << "Stack converted to linked list." << endl;
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

