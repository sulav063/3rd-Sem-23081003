#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertFront(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

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
        Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL || temp->next == head) {
                cout << "Invalid position." << endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertEnd(int data) {
        if (head == NULL) {
            insertFront(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void traverse() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void deleteFront() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        if (head == temp) {
            delete head;
            head = NULL;
        } else {
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
    }

    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            delete head;
            head = NULL;
        } else {
            prev->next = head;
            delete temp;
        }
    }

    void deleteAtPosition(int position) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        if (position == 1) {
            deleteFront();
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        for (int i = 0; i < position - 1; i++) {
            prev = temp;
            temp = temp->next;
            if (temp == head) {
                cout << "Invalid position." << endl;
                return;
            }
        }
        prev->next = temp->next;
        delete temp;
    }
};

int main() {
    CircularLinkedList list;
    int choice, data, position;

    do {
        cout << "\nCircular Linked List Menu:" << endl;
        cout << "1. Insert at front" << endl;
        cout << "2. Insert at position" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Delete from front" << endl;
        cout << "5. Delete from positon" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Traverse" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at front: ";
                cin >> data;
                list.insertFront(data);
                break;
            case 2:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                list.insertAtPosition(data, position);
                break;
            case 3:
                cout << "Enter data to insert at end: ";
                cin >> data;
                list.insertEnd(data);
                break;
            case 4:
                list.deleteFront();
                break;
            case 5:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;
            case 6:
                list.deleteEnd();
                break;
            case 7:
                cout << "List contents: ";
                list.traverse();
                break;
            case 8:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}
