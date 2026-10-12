#include <iostream>
#include <stdexcept>
using namespace std;

class List
{
private:
    struct Node
    {
        int data;
        Node* next;
    };

    Node* head;

public:
    List()
    {
        head = nullptr;
    }

    void add(int value)
    {
        Node* newNode = new Node{ value, nullptr };

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void remove()
    {
        if (head == nullptr)
        {
            throw runtime_error("List is empty!");
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void show()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~List()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    List list;

    try
    {
        list.add(10);
        list.add(20);
        list.add(30);
        cout << "List: ";
        list.show();
        list.remove();
        cout << "After deleting: ";
        list.show();
        list.remove();
        list.remove();
        list.remove();
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
}
