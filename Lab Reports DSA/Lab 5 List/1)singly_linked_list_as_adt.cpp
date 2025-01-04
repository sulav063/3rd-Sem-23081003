#include <iostream>
using namespace std;

// Define the structure of a node
struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head; 

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Destructor to free allocated memory
    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
    }

    // Function to insert node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert node at specific position
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node();
        newNode->data = value;

        if (position == 1 || head == NULL) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current != NULL; ++i) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Position out of range\n";
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to insert node at end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Function to delete node from beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to delete node from specific position
    void deleteFromPosition(int position) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = NULL;
        for (int i = 1; i < position && current != NULL; ++i) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Position out of range\n";
            return;
        }

        prev->next = current->next;
        delete current;
    }

    // Function to delete node from end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        Node* prev = NULL;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }

        prev->next = NULL;
        delete current;
    }

    // Function to traverse and print the list
    void traverse() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, data, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at specific position\n";
        cout << "3. Insert at end\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from specific position\n";
        cout << "6. Delete from end\n";
        cout << "7. Traverse\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert: ";
                cin >> position;
                list.insertAtPosition(data, position);
                break;
            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteFromPosition(position);
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Linked List: ";
                list.traverse();
                break;
            case 8:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 8);

    return 0;
}
