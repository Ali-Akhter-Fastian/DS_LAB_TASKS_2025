#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    string data;
    Node()
    {
        next = NULL;
    }
    Node(string val)
    {
        data = val;
        next = NULL;
    }
};
class stack
{
private:
    Node *top;
    int currsize;
    int maxsize;

public:
    stack(int size)
    {
        this->maxsize = size;
        currsize = 0;
        top = NULL;
    }
    void push(string val)
    {
        if (currsize == maxsize)
        {
            cout << "stack is full"<<endl;
            return;
        }
        Node *newNode = new Node(val);
        if (currsize == 0)
        {
            top = newNode;
            top->next = NULL;
            currsize++;
        }
        else
        {
            newNode->next = top;
            top = newNode;
            currsize++;
        }
    }
    string pop()
    {
        if (currsize == 0)
        {
            cout << "stack is empty"<<endl;
            return NULL;
        }
        string element = top->data;
        if (currsize == 1)
        {
            Node *temp = top;
            delete temp;
            top = NULL;
            currsize--;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
            currsize--;
        }
        return element;
    }
    bool is_empty()
    {
        if (currsize == 0)
            return true;
        else
            return false;
    }
    int size()
    {
        return currsize;
    }
};
class item{
    stack items;
    int max_items;
    int itemcount;
    public:
    item(int size):items(size){
        max_items = size;
        itemcount = 0;
    }
    void Add_item(string item1){
        if(itemcount == max_items){
            cout<<"Limit to manage items reached, can't add more"<<endl;
            return;
        }
       items.push(item1);
        itemcount++;
        cout<<"Item Added"<<endl;
    }
    string remove(){
        string temp =items.pop();
        return temp;
    }
    bool is_empty_items(){
        bool check = items.is_empty();
        return check;
    }
    int currsize(){
        int s=items.size();
        return s;
    }

};
int main()
{
    item t(2);
    t.Add_item("Bathing");
    t.Add_item("studying");
     t.Add_item("playing");
    string s;
    s = t.remove();
     cout<<s<<endl;
      bool c1 = t.is_empty_items();
    cout<<c1;
    s = t.remove();
    cout<<s<<endl;
    bool c = t.is_empty_items();
    cout<<c;
}