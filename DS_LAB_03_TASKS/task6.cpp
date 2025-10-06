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

class List
{

    Node *head;
    Node *tail;

public:
    List()
    {

        head = tail = NULL;
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

    ll.Insert_at_end(3);
    ll.Insert_at_end(1);
    ll.Insert_at_end(2);
    ll.Insert_at_end(5);
    ll.Insert_at_end(8);
    ll.print();
    int val;
    do{
        cout << "Enter the value to delete: ";
        cin>>val;
        ll.deleteAtPos(val);
        cout << "Linked list after deleting " << val << ": " << endl;
        ll.print();

        cout<<endl<<"Enter any key except integers to exit!!!"<<endl<<endl;
    }while (!cin.fail());
}
