#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{

    Node *head;
    Node *tail;

public:
    List()
    {

        head = tail = NULL;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    bool checkPalindrome()
    {

        Node *temp = head;
        int lengthOfLinkedList = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            lengthOfLinkedList++;
        }

        int mid;

        if (lengthOfLinkedList % 2 == 0)
        {
            mid = lengthOfLinkedList / 2;
        }
        else
        {
            mid = (lengthOfLinkedList / 2) + 1;
        }

        int i = 0;
        int part1 = 0, part2 = 0, midValue;
        temp = head;
        while (temp != NULL)
        {
            i++;
            if (i < mid)
            {
                part1 += temp->data;
            }
            else if (i == mid && lengthOfLinkedList % 2 == 0)
            {
                midValue = temp->data;
                midValue += temp->next->data;
                temp = temp->next;
            }
            else if (i == mid && lengthOfLinkedList % 2 != 0)
            {
                midValue = temp->data;
            }
            else
            {
                part2 += temp->data;
            }
            temp = temp->next;
        }

        if (part1 + midValue == part2 + midValue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print(){
        Node *iterator=head;
        while(iterator!=NULL){
            cout<<iterator->data<<" -> ";
            iterator=iterator->next;
        }
        cout<<"NULL"<<endl;
    };
};

int main()
{

    List ll;

    ll.push_back(1);
    ll.push_back(0);
    ll.push_back(2);
    ll.push_back(0);
    ll.push_back(1);
    ll.print();
    cout << endl;
    bool isPalindrome = ll.checkPalindrome();
    if (isPalindrome)
        cout << endl<< "Linked List is a Palindrome" << endl;
    else
        cout << endl     << "Linked List is not a Palindrome" << endl;
}
