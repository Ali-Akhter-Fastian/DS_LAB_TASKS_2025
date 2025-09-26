#include<iostream>
using namespace std;
class Exam{
    string *studentname=NULL;
    string *examdate=NULL;
    double *score=NULL;
    public:
    Exam(){}
   void  set_name(string name){
        if(studentname!=NULL){
           *studentname=name;
        }else{
        studentname=new string(name);
        }
    }
    void set_date(string date){
        if(examdate!=NULL){
            *examdate=date;
        }else{
        examdate=new string(date);
        }
    }
   void  set_score(double scor){
        if(score!=NULL){
            *score=scor;

        }else{
            score=new double(scor);
        }
    }
   void  printExamDetails(){
        cout<<"Name: "<<*studentname<<endl;
        cout<<"Date: "<<*examdate<<endl;
        cout<<"Score: "<<*score<<endl;
    }
};
int main(){
    Exam e1;
    e1.set_name("John");
    e1.set_date("12/12/2025");
    e1.set_score(100);
    cout<<endl<<"EXAM 1"<<endl;
    e1.printExamDetails();
    Exam e2=e1;
    
     cout<<endl<<"EXAM 2"<<endl;
    e2.printExamDetails();
    cout<<endl<<"EXAM 2 is same as EXAM 1 after copying"<<endl;
    e2.set_name("Jane");
    e2.set_date("11/11/2025");
    e2.set_score(90);
    cout<<endl<<"EXAM 2 details has been changed"<<endl;
     cout<<endl<<"EXAM 2"<<endl;
    e2.printExamDetails();
    cout<<endl<<"The change in EXAM 2 also changes the EXAM 1"<<endl;
     cout<<endl<<"EXAM 1"<<endl;
    e1.printExamDetails();
    return 0;
}
//If we do shallow copy than the pointers of both the object points to the same memory address, which causes issue
// when the scope ends the the destructor runs. For two objects the destructor runs twice to delete the same memory
// address which is an issue which we can't see. 