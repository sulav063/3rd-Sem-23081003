/*WAP to demonstrate queue as ADT with following activities
a.make empty
b.check queue is full or not
c.check queue is empty or not
d.Inqueue
e.Dequeue
f.Traversal*/
#include <iostream>
#define max 5
using namespace std;

class Queue
{
private:
    int array[max], rear, front;

public:
    void queueResetter()
    {
        rear = -1;
        front = 0;
    }
    void enque()
    {
        if (isFull() == 1)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            int enqueValue;
            cout << "Enter a number to enque into the queue: " << endl;
            cin >> enqueValue;
            rear++;
            array[rear] = enqueValue;
        }
        if (isFull() != 1)
        {
            cout << array[rear] << " has been enqued to the queue." << endl;
        }
    }
    void deque()
    {
        if (isEmpty() == 1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << array[front] << " has been dequed.";
            front++;
        }
    }
    bool isEmpty()
    {
        if (rear < front)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool isFull()
    {
        if (rear == max - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void peek()
    {
        cout << "The value in front of the queue is :" << array[front] << endl;
    }

    void menuDriven()
    {
        queueResetter();
        int userInput = 0;
        do
        {
            cout << "Enter a number to select from the operations below: " << endl;
            cout << "1 ) Enque" << endl;
            cout << "2 ) Deque" << endl;
            cout << "3 ) Check if queue is empty?" << endl;
            cout << "4 ) Check if queue is full?" << endl;
            cout << "5 ) Peek" << endl;
            cout << "6 ) Make queue empty" << endl;
            cout << "7 ) Exit" << endl;
            cin >> userInput;
            switch (userInput)
            {
            case 1:
                enque();

                break;
            case 2:
                deque();
                break;
            case 3:
                if (isEmpty() == 1)
                {
                    cout << "Queue is empty." << endl;
                }
                else
                {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 4:
                if (isFull() == 1)
                {
                    cout << "Queue is full." << endl;
                }
                else
                {
                    cout << "Queue is not full." << endl;
                }
                break;
            case 5:
                peek();
                break;
            case 6:
                queueResetter();
                cout << endl
                    << "Queue is empty now." << endl;
                break;
            case 7:
                cout << "Exiting program...";
            default:
                cout << "Enter the number again..." << endl;
                break;
            }
        } while (userInput != 7);
    }
};

int main()
{
    Queue q1;
    q1.menuDriven();
}