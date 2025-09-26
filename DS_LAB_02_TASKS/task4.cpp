#include<iostream>
using namespace std;
int main(){
    cout<<endl<<"~~~NUMBER OF DEPARTMENTS INPUT~~~"<<endl<<endl;
    int row;
    cout<<"Enter number of departments: ";
    cin>>row;
    int size[row];
    string nameOfDep[row];
    cout<<endl<<"~~~NAME OF DEPARTMENTS~~~"<<endl<<endl;
    for(int i=0;i<row;i++){
        cout<<"Enter name of department "<<i+1<<": ";
        cin>>nameOfDep[i];
    }
    cout<<endl<<"~~~NUMBER OF CORE COURSES INPUT~~~"<<endl<<endl;
    for(int i=0;i<row;i++){
        cout<<"Enter no of core courses in  "<<nameOfDep[i]<<" : ";
        cin>>size[i];
    }
    float **arr= new float*[row];
    for(int i=0;i<row;i++){
        arr[i]=new float[size[i]];
    }
    cout<<endl<<"~~~CGPA OF COURSES~~~"<<endl<<endl;
    for(int i=0;i<row;i++){
        cout<<"CGPA OF "<<nameOfDep[i]<<endl;
        for(int j=0;j<size[i];j++){
            cout<<"Course "<<j+1<<" CGPA: ";
            cin>>arr[i][j];
        }
    }
     cout<<endl<<"~~~OUTPUT~~~"<<endl<<endl;
     cout<<endl<<"~~~CGPA OF COURSES~~~"<<endl<<endl;
    for(int i=0;i<row;i++){
        cout<<"CGPA OF "<<nameOfDep[i]<<endl;
        for(int j=0;j<size[i];j++){
            cout<<"Course "<<j+1<<" CGPA: "<<arr[i][j]<<endl;
        }
        cout<<endl;
    }
}