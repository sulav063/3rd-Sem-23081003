#include <iostream>

using namespace std;

// Node class for a doubly circular linked list
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

// Doubly circular linked list class
class DoublyCircularLinkedList {
private:
    Node* head;

public:
    DoublyCircularLinkedList() {
        head = NULL;
    }

    // Function to insert a node at the front of the list
    void insertFront(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at a specific position in the list
    void insertAtPosition(int data, int position) {
        if (position <= 0) {
            cout << "Invalid position." << endl;
            return;
        }
        if (position == 1) {
            insertFront(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* current = head;
        for (int i = 1; i < position - 1 && current->next != head; i++) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Invalid position." << endl;
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }

    // Function to insert a node at the end of the list
    void insertEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    // Function to delete a node from the front of the list
    void deleteFront() {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete temp;
    }

    // Function to delete a node from a specific position in the list
    void deleteAtPosition(int position) {
        if (position <= 0 || head == NULL) {
            cout << "Invalid position or list is empty." << endl;
            return;
        }
        if (position == 1) {
            deleteFront();
            return;
        }
        Node* current = head;
        for (int i = 1; i < position && current->next != head; i++) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Invalid position." << endl;
            return;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }

    // Function to delete a node from the end of the list
    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head->prev;
        head->prev = temp->prev;
        temp->prev->next = head;
        delete temp;
    }

    // Function to traverse and display the list from beginning
    void traverseFromBeginning() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        cout << "Doubly Circular Linked List (Forward): ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    // Function to traverse and display the list from behind
    void traverseFromBehind() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head->prev;
        cout << "Doubly Circular Linked List (Backward): ";
        do {
            cout << current->data << " ";
            current = current->prev;
        } while (current != head->prev);
        cout << endl;
    }

    // Function to search for a value in the list
    bool search(int value) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return false;
        }
        Node* current = head;
        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != head);
        return false;
    }

    // Destructor to free memory
    ~DoublyCircularLinkedList() {
        if (head != NULL) {
            Node* current = head;
            do {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            } while (current != head);
        }
    }
};

int main() {
    DoublyCircularLinkedList dcll;

    while (true) {
        cout << "\nDoubly Circular Linked List Operations:" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Specific Position" << endl;
        cout << "3. Insert from End" << endl;
        cout << "4. Delete from Front" << endl;
        cout << "5. Delete from Specific Position" << endl;
        cout << "6. Delete from End" << endl;
        cout << "7. Traverse from Beginning" << endl;
        cout << "8. Traverse from Behind" << endl;
        cout << "9. Search" << endl;
        cout << "10. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to insert at front: ";
                cin >> data;
                dcll.insertFront(data);
                break;
            }
            case 2: {
                int data, position;
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                dcll.insertAtPosition(data, position);
                break;
            }
            case 3: {
                int data;
                cout << "Enter data to insert at end: ";
                cin >> data;
                dcll.insertEnd(data);
                break;
            }
            case 4:
                dcll.deleteFront();
                break;
            case 5: {
                int position;
                cout << "Enter position to delete from: ";
                cin >> position;
                dcll.deleteAtPosition(position);
                break;
            }
            case 6:
                dcll.deleteEnd();
                break;
            case 7:
                dcll.traverseFromBeginning();
                break;
            case 8:
                dcll.traverseFromBehind();
                break;
            case 9: {
                int value;
                cout << "Enter value to search for: ";
                cin >> value;
                if (dcll.search(value)) {
                    cout << "Value found in the list." << endl;
                } else {
                    cout << "Value not found in the list." << endl;
                }
                break;
            }
            case 10:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
