// IMPLEMENT STACK USING ARRAYS
#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    char data;
    Node()
    {
        this->next = NULL;
    }
    Node(char val)
    {
        this->data = val;
        this->next = NULL;
    }
};
class Stack
{
private:
    Node *top;
    int maxsize;
    int currsize;

public:
    Stack(int maxsize)
    {
        this->maxsize = maxsize;
        currsize = 0;
        top = NULL;
    }
    void Push(char c)
    {
        if (currsize == maxsize)
        {
            cout << "Stack reached its limit";
            return;
        }
        Node *newNode = new Node(c);
        newNode->next = top;
        top = newNode;
        currsize++;
    }
    char get_top()
    {
        if (currsize == 0)
        {
            cout << "stack is empty";
            return -1;
        }
        return top->data;
    }
    void pop()
    {
        if (currsize == 0)
        {
            cout << "stack is empty";
            return;
        }
        Node *temp = top;
        if (currsize == 1)
        {
            top = NULL;
            delete temp;
            currsize--;
        }
        else
        {
            top = top->next;
            delete temp;
            currsize--;
        }
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
bool check(string s)
{
    Stack st(100);
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.Push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if(st.is_empty())   return false;
            if ((s[i] == ')' && st.get_top() == '(') ||
                (s[i] == '}' && st.get_top() == '{') ||
                (s[i] == ']' && st.get_top() == '['))
            {
                st.pop();
                continue;
            }
            else return false;
        }
    }
    if(st.is_empty())   return true;
    else return false;
}

int main(){
    string s = ")";
    bool flag = check(s);
    if(flag) cout<<"BALANCED PARANTHESIS";
    else cout<<"NOT BALANCED";
}