#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CircularList
{

    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = NULL;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = head;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = head;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    void insertAtPos(int pos, int val)
    {

        Node *newNode = new Node(val);
        Node *temp = head;
        Node *temp2 = NULL;

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        temp2 = temp->next;
        temp->next = newNode;
        newNode->next = temp2;
    }

    void deleteAtPos(int val)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *prev = NULL;
        Node *temp = head;
        Node *temp2 = NULL;

        do
        {
            prev = temp;
            temp = temp->next;
        } while (temp != tail && temp->data != val);

        if (temp == tail && tail->data != val)
        {
            cout << "The value "<<val<< " is not present!!!" << endl;
            return;
        }
        if (temp == head)
        {
            head = head->next;
            delete temp;
        }
        else
        {
            temp2 = temp->next;
            delete temp;
            prev->next = temp2;
        }
    }

    void printLinkedList()
    {
        Node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main()
{
    CircularList cll;
    
    cll.push_back(1);
    cll.push_back(2);
    cll.push_back(3);
    cll.push_back(4);
    cll.push_back(5);
    cll.push_back(6);

    cll.push_front(7);
    cll.push_front(8);

    cll.insertAtPos(3, 120);
    cll.insertAtPos(5, 100);

    cll.deleteAtPos(120);
    cll.deleteAtPos(5);
    cll.deleteAtPos(9);
    cll.deleteAtPos(6);

    cll.printLinkedList();
    return 0;
}
