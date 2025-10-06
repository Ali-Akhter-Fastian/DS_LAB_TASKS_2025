#include<iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
    Node (int val){
        this->data = val;
        this->next = NULL;
    }

};
class List{
    Node *head ;
    Node *tail;
    public:
    List(){
        head=tail=NULL;
    }
    void Sort_Even_Odd(){
        Node *iterator = head;
        Node *tempe = NULL;
        Node *prev = head;
        while(iterator!=NULL){
            if((prev->data) % 2 == 0){
                tempe = prev;
            }
            if((iterator->data) % 2 == 0 && (prev->data) % 2 != 0){
                if(tempe == NULL){
                    prev->next = iterator->next;
                    iterator->next = head;
                    head = iterator;
                    tempe = head;
                }
                else {
                    prev->next = iterator->next;
                    iterator->next = tempe->next;
                    tempe->next = iterator;
                    tempe = iterator;
                }
                
            }
            prev = iterator;
            iterator= iterator->next; 

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
    void print(){
        Node *iterator=head;
        while(iterator!=NULL){
            cout<<iterator->data<<" -> ";
            iterator=iterator->next;
        }
        cout<<"NULL"<<endl;
    };
};
int main(){
    List ll;
    int choice;
    int val;

    do {
        cout << "\n===== Passenger Reservation System =====\n";
        cout << "1. Add Element\n";
        cout << "2. Sort even and odd\n";
         cout << "3. Display All\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Add element: ";
            cin >> val;
            ll.Insert_at_end(val);
            break;
        case 2:
            ll.Sort_Even_Odd();
            break;
        case 3:
            ll.print();
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;

}