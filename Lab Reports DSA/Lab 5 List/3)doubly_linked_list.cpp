#include <iostream>

using namespace std;

// Node class for a doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Function to insert a node at the front of the list
    void insertFront(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at a specific position in the list
    void insertAtPosition(int data, int position) {
        if (position < 0) {
            cout << "Invalid position." << endl;
            return;
        }
        if (position == 0) {
            insertFront(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* current = head;
        for (int i = 0; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Invalid position." << endl;
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }

    // Function to insert a node at the end of the list
    void insertEnd(int data) {
        Node* newNode = new Node(data);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to delete a node from the front of the list
    void deleteFront() {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
    }

    // Function to delete a node from a specific position in the list
    void deleteAtPosition(int position) {
        if (position < 0 || head == NULL) {
            cout << "Invalid position or list is empty." << endl;
            return;
        }
        if (position == 0) {
            deleteFront();
            return;
        }
        Node* current = head;
        for (int i = 0; i < position && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Invalid position." << endl;
            return;
        }
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != NULL) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
        delete current;
    }

    // Function to delete a node from the end of the list
    void deleteEnd() {
        if (tail == NULL) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        delete temp;
    }

    // Function to traverse and display the list
    void traverse() {
        Node* current = head;
        cout << "Doubly Linked List: ";
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to search for a value in the list
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

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = NULL;
        tail = NULL;
    }
};

int main() {
    DoublyLinkedList dll;

    while (true) {
        cout << "\nDoubly Linked List Operations:" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Specific Position" << endl;
        cout << "3. Insert from End" << endl;
        cout << "4. Delete from Front" << endl;
        cout << "5. Delete from Specific Position" << endl;
        cout << "6. Delete from End" << endl;
        cout << "7. Traverse" << endl;
        cout << "8. Search" << endl;
        cout << "9. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to insert at front: ";
                cin >> data;
                dll.insertFront(data);
                break;
            }
            case 2: {
                int data, position;
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                dll.insertAtPosition(data, position);
                break;
            }
            case 3: {
                int data;
                cout << "Enter data to insert at end: ";
                cin >> data;
                dll.insertEnd(data);
                break;
            }
            case 4:
                dll.deleteFront();
                break;
            case 5: {
                int position;
                cout << "Enter position to delete from: ";
                cin >> position;
                dll.deleteAtPosition(position);
                break;
            }
            case 6:
                dll.deleteEnd();
                break;
            case 7:
                dll.traverse();
                break;
            case 8: {
                int value;
                cout << "Enter value to search for: ";
                cin >> value;
                if (dll.search(value)) {
                    cout << "Value found in the list." << endl;
                } else {
                    cout << "Value not found in the list." << endl;
                }
                break;
            }
            case 9:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
