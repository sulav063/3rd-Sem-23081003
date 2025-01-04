/*WAP to demonstrate stack as ADT, to peroform following activities
a.Make empty stack
b.check empty stack
c.check full stack
d.push operation
e.pop operation
f.peak/top operation
g.stack traversal*/
#include <iostream>
using namespace std;

class Stack {
public:
    int data[5];
    int count;

    Stack() {
        this->count = -1;
    }

    void makeEmpty() {
        count = -1;
    }

    bool checkEmpty() {
        return (count < 0);
    }

    bool checkFull() {
        return (count + 1 == 5); 
    }

    void push() {
        if (checkFull()) {
            cout << "Stack Overflow: Cannot push, stack is full." << endl;
        } else {
            cout << "Enter data: ";
            ++count;
            cin >> data[count];
            cout << data[count] << " pushed to the stack." << endl;
        }
    }

    void pop() {
        if (checkEmpty()) {
            cout << "Stack Underflow: Cannot pop, stack is empty." << endl;
        } else {
            int removedElement = data[count];
            --count;
            cout << removedElement << " popped from the stack." << endl;
        }
    }

    void peek() {
        if (checkEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element of the stack: " << data[count] << endl;
        }
    }

    void stackTraverse() {
        if (checkEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= count; ++i) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack myStack;
    int choice;

    do {
        cout << "Menu" << endl;
        cout << "1. Make the stack empty." << endl;
        cout << "2. Check if the stack is empty." << endl;
        cout << "3. Check if the stack is full." << endl;
        cout << "4. Push to the stack." << endl;
        cout << "5. Pop from the stack." << endl;
        cout << "6. Peek the top element." << endl;
        cout << "7. Traverse the stack." << endl;
        cout << "8. Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myStack.makeEmpty();
                break;
            case 2:
                if (myStack.checkEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 3:
                if (myStack.checkFull()) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;
            case 4:
                myStack.push();
                break;
            case 5:
                myStack.pop();
                break;
            case 6:
                myStack.peek();
                break;
            case 7:
                myStack.stackTraverse();
                break;
            case 8:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 8);

    return 0;
}
