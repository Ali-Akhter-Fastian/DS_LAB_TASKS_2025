#include<iostream>
using namespace std;
class Node{
    public:
    Node *next;
    string data;
    Node(string data){
        next=NULL;
        this->data=data;
    }
};
class List{
    Node *head;
    Node *tail;
    public:
    List(){
        head=tail=NULL;
    }
    void Add_Passenger(string name){
        Node *newNode = new Node(name);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void Cancel_Reservation(string name){
        Node *iterator=head;
        Node *temp=head;
        while(iterator!=NULL){
            if(iterator == head && iterator->data == name){
                head= iterator->next;
                delete iterator;
                return;
            }
            else if(iterator->data==name){
                temp->next = iterator->next;
                delete iterator;
                return;
            }
            temp = iterator;
            iterator = iterator->next;
        }
        cout<<"Passenger does not exist"<<endl;
    }
    void Check_reservation(string name){
        Node *iterator = head;
         while(iterator!=NULL){
            if(iterator->data==name){
               cout<<"Seat is reserved for the passenger named "<<name<<endl;
               return;
            }
            iterator = iterator->next;
        }
        cout<<"Your seat is not reserved"<<endl;
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
    string name;

    do {
        cout << "\n===== Passenger Reservation System =====\n";
        cout << "1. Add Passenger\n";
        cout << "2. Cancel Reservation\n";
        cout << "3. Check Reservation\n";
        cout << "4. Display All Passengers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter passenger name: ";
            cin >> name;
            ll.Add_Passenger(name);
            break;
        case 2:
            cout << "Enter passenger name to cancel: ";
            cin >> name;
            ll.Cancel_Reservation(name);
            break;
        case 3:
            cout << "Enter passenger name to check: ";
            cin >> name;
            ll.Check_reservation(name);
            break;
        case 4:
            ll.print();
            break;
        case 5:
            cout << "Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}