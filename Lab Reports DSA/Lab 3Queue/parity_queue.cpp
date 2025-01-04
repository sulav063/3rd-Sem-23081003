#include <iostream>
#include <queue>
using namespace std;

class PriorityQueueManager {
private:
    priority_queue<int> pq;

public:
    void enqueue(int val)
    {
        pq.push(val);
    }

    void dequeue()
    {
        if (pq.size() > 0)
        {
            cout << "Element dequeued from priority queue is: " << pq.top() << endl;
            pq.pop();
        }
        else
        {
            cout << "Priority Queue is empty. Cannot dequeue.\n";
        }
    }

    void display()
    {
        if (pq.size() == 0)
        {
            cout << "Priority Queue is empty.\n";
        }
        else
        {
            priority_queue<int> temp = pq; // Create a temporary copy
            cout << "Priority Queue elements: ";
            while (!temp.empty())
            {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }
};

int main()
{
    PriorityQueueManager manager;
    int ch, val;

    do
    {
        cout << "1) Enqueue a data in priority queue.\n";
        cout << "2) Dequeue a data in priority queue.\n";
        cout << "3) Display priority queue.\n";
        cout << "4) Exit.\n";
        cout << "Enter choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter data to enqueue: ";
            cin >> val;
            manager.enqueue(val);
            break;

        case 2:
            manager.dequeue();
            break;

        case 3:
            manager.display();
            break;

        case 4:
            cout << "Exit\n";
            break;

        default:
            cout << "Incorrect choice!\n";
        }
    } while (ch != 4);

    return 0;
}
