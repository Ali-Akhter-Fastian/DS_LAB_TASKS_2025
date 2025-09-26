#include<iostream>
using namespace std;
class Box{
    int *value=NULL;
    public:
    Box(){};
    Box(Box &obj){
        this->value=obj.value;
    }
    // Box(Box &obj){
    //     this->value=new int(*(obj.value));
    // }
    void operator =(Box &obj){
        this->value=new int(*(obj.value));
    }
    void set_value(int val){
        if(value!=NULL){
            *value=val;
        }else{
            value=new int(val);
        }
    }
    void showvalue(){
        cout<<"VALUE: "<<*value<<endl;
    }
    ~Box(){
        if(value!=NULL){
            delete value;
        }
    }
};
int main(){
    Box obj1;
    obj1.set_value(23);
    Box obj2=obj1;
    obj2.set_value(12);
    obj2.showvalue();
    obj1.showvalue();
}