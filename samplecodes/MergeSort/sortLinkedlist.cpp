#include<iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
    Node(int val){
        data = val;
        next = NULL;
    }
    Node (){
        next = NULL;
    }
};
class List{
    public:
    Node *head;
    Node *tail;
    List(){
        head = tail =NULL;
    }
    void Inset_AT_End(int val){
        Node *newNode = new Node(val);
        if(head==NULL)  head = tail = newNode;
        else {
            tail->next = newNode;
            tail=newNode;
            tail->next = NULL;
        }
    }
    void print(){
        Node *iterator = head;
        while(iterator!=NULL){
            cout<<iterator->data<<"->";
            iterator=iterator->next;
        }
        cout<<"NULL"<<endl;
    }
     void print(Node *head){
        Node *iterator = head;
        while(iterator!=NULL){
            cout<<iterator->data<<"->";
            iterator=iterator->next;
        }
        cout<<"NULL"<<endl;
    }
    Node* Find_middle(Node *head){
        Node* slow=head;
        Node* fast = head->next;
        while(fast!=NULL  && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* MergeTwoList(Node* list1, Node* list2){
        Node* DummyPointer=new Node(-1);
        Node* temp = DummyPointer;
        while(list1!=NULL && list2!=NULL){
            if(list1->data<list2->data){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1)   temp->next=list1;
        else temp->next=list2;
        return DummyPointer->next;
    }
    Node *SortLL(Node *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* middle = Find_middle(head);
        Node * right = middle->next;
        middle->next=NULL;
        Node * left = head;
        left = SortLL(left);
        right = SortLL(right);
        return MergeTwoList(left,right);
    }
    void sort(){
       head=SortLL(head);
        print();
    }
};

int main(){
    List ll;
    ll.Inset_AT_End(34);
    ll.Inset_AT_End(90);
    ll.Inset_AT_End(2);
    ll.Inset_AT_End(23);
    ll.print();
    ll.sort();
}