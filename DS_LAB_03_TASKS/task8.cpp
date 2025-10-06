#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {

        head = tail = NULL;
    }

    void concatenateTwoDoublyLinkedLists(Node *secondListhead)
    {

        Node *tempHead1 = this->head;
        Node *tempHead2 = secondListhead;

        while (tempHead1 != nullptr && tempHead2 != nullptr)
        {
            Node *next1 = tempHead1->next;
            Node *next2 = tempHead2->next;
            
          
            tempHead1->next = tempHead2;
            tempHead2->prev = tempHead1;

            if (next1 != nullptr)
            {
                tempHead2->next = next1;
                next1->prev = tempHead2;
            }

            tempHead1 = next1;
            tempHead2 =next2;
        }
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
    }

    void printLinkedList()
    {
        Node *temp = head;
        int i = 0;
        while (temp != NULL)
        {

            cout << temp->data << "->";
            temp = temp->next;
        };
        cout << "NULL"<<endl;
    }
};

int main()
{
    DoublyLinkedList dll1, dll2;
    dll1.push_back(1);
    dll1.push_back(3);
    dll1.push_back(5);
    dll1.push_back(7);
    dll1.push_back(9);
    dll1.push_back(11);

    cout<<"\n~~First linked list~~"<<endl;
    dll1.printLinkedList();

    dll2.push_back(2);
    dll2.push_back(4);
    dll2.push_back(6);
    dll2.push_back(8);
    dll2.push_back(10);
    dll2.push_back(12);

    cout<<"\n~~Second linked list~~"<<endl;
    dll1.printLinkedList();

    dll1.concatenateTwoDoublyLinkedLists(dll2.head);

    cout<<"\n~~After concatenating~~"<<endl;
    dll1.printLinkedList();
}
