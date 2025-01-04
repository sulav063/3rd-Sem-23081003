 /*WAP to demonstrate list as ADT, to peroform following activities
a.Make empty list
b.check empty list
c.check full list
d.insert on list
e.delete from list
f.traverse the list*/
#include <iostream>
using namespace std;

class list
{
public:
    int data[5];
    int count;

    list()
    {
        this->count = -1;
    }

    void makeempty()
    {
        count = -1;
    }

    int checkempty()
    {
        if (count < 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int checkfull()
    {
        if ((count + 1) == 5)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void insert_data()
    {
        if (checkfull())
        {
            cout << "The data cannot be entered." << endl;
        }
        else
        {
            cout << "Enter data:" << endl;
            ++count;
            cin >> data[count];
        }
    }

    void deletedata(int del)
    {
        if (checkempty())
        {
            cout << "The list is empty so you cannot delete the data." << endl;
        }
        else
        {
            int temp = data[del];
            for (int i = del; i < count; i++)
            {
                data[i] = data[i + 1];
            }
            --count;
            cout << temp << " was deleted from the list." << endl;
        }
    }

    void traverse()
    {
        if (checkempty())
        {
            cout << "The given list has no data." << endl;
        }
        else
        {
            cout << "The required data is: ";
            for (int i = 0; i <= count; i++)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n = 0;
    list l;

    do
    {
        cout << "Menu" << endl;
        cout << "Press 1 to Make the list empty." << endl;
        cout << "Press 2 to Check if the list is empty or not." << endl;
        cout << "Press 3 to Check if the list is full or not." << endl;
        cout << "Press 4 to Insert the data to the list." << endl;
        cout << "Press 5 to Delete the data form the list." << endl;
        cout << "Press 6 to See the list." << endl;
        cout << "Press any Key to exit." << endl;
        cin >> n;

        switch (n)
        {
        case 1:
            l.makeempty();
            break;
        case 2:
            if (l.checkempty())
            {
                cout << "The given list is empty." << endl;
            }
            else
            {
                cout << "The given list is not empty." << endl;
            }
            break;
        case 3:
            if (l.checkfull())
            {
                cout << "The given list is full." << endl;
            }
            else
            {
                cout << "The given list is not full." << endl;
            }
            break;
        case 4:
            l.insert_data();
            break;
        case 5:
            cout << "Enter the index of the data that you want to delete" << endl;
            int del;
            cin >> del;
            l.deletedata(del - 1);
            break;
        case 6:
            l.traverse();
            break;
        default:
            n = 7;
        }
    } while (n != 7);

    return 0;
}
