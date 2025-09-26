#include<iostream>
using namespace std;
int main(){
    int row;
    cout<<"Enter the total rows of seats in the hall: ";
    cin>>row;
    int seats[row];
    for(int i=0;i<row;i++){
        cout<<"Enter no of seats in row "<<i+1<<": ";
        cin>>seats[i];
    }
    string **arr = new string*[row];
    for(int i=0;i<row;i++){
        arr[i] = new string [seats[i]];
    }
    for(int i=0;i<row;i++){
        cout<<endl<<"ROW "<<i+1<<" "<<endl;
        for(int j=0;j<seats[i];j++){
            cout<<"Enter name of attendee in seat "<<j+1<<": ";
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<"~~~OUTPUT~~~"<<endl;
     for(int i=0;i<row;i++){
        cout<<endl<<"ROW "<<i+1<<" "<<endl;
        for(int j=0;j<seats[i];j++){
            cout<<"Name of attendee in seat "<<i+1<<"is : "<<arr[i][j]<<endl;
        }
        cout<<endl;
    }
}