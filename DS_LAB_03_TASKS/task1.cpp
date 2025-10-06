#include <bits/stdc++.h>
using namespace std;
struct Node
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
class List
{
private:
    Node *head=NULL;
    Node *tail=NULL;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void Insert_array(int arr[], int size)
    {
        Node *temp=NULL;
        for (int i = 0; i < size; i++)
        {
            Node *newNode = new Node(arr[i]);
            if (i == 0)
            {
                head = newNode;
                temp=head;
            }
            temp->next=newNode;
            temp=newNode;
            
        }
    }
    void Insert_at_end(int val){
        Node *newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            Node *iterator=head;
            while(iterator!=NULL){
                if(iterator->next==NULL){
                    iterator->next=newNode;
                    tail=newNode;
                    tail->next=NULL;
                    cout<<"NODE ADDED"<<endl;
                    return;
                }
                iterator=iterator->next;
            }
        }
    }
    void Insert_At_Position(int pos , int val){
        Node *iterator = head;
        Node *newNode = new Node(val);
        int count=1;
        while(iterator!=NULL){
            if(pos == 0){
                head = newNode;
                head->next = iterator;
                return;
            }
            else if(count == pos - 1){
                newNode->next = iterator->next;
                iterator->next = newNode;
                return;
            }
            iterator = iterator->next;
            count++;
        }
    }
    void print()
    {
        Node *iterator = head;
        while (iterator != NULL)
        {
            cout << iterator->data << " -> ";
            iterator = iterator->next;
        }
        cout << "NULL" << endl;
    };
   void deleteAtPos(int val)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *prev = NULL;
        Node *temp = head;
        Node *temp2 = NULL;

        while (temp != NULL && temp->data != val)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "The value " << val << " is not present in the list" << endl
                 << endl;
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


    void Insert_At_front(int val){
        Node *newNode = new Node(val);
        newNode->next=head;
        head=newNode;
    }

};

int main()
{
    int arr[] = {3, 1, 2, 5, 8};
    cout<<"Present array: ";
    for (int i = 0; i < 5; i++)
        cout << arr[i]<<" ";
    cout<<endl;
    List ll;
    ll.Insert_array(arr, 5);
    cout<<"List: ";
    ll.print();
    ll.Insert_at_end(9);
    ll.Insert_At_Position(3,11);
    ll.print();
    ll.deleteAtPos(1);
    ll.deleteAtPos(2);
    ll.deleteAtPos(5);
    ll.print();
    ll.Insert_At_front(4);
    ll.print();
    cout << endl;
}