#include<iostream>
using namespace std;
int main(){
    int n=10,count=0;
    int arr[n];
    cout<<"Enter 10 elemnts: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        count++;
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        if(count<=3){
            cout<<"Minimun Elements no "<<i+1<<": "<<arr[min_index]<<endl;
        }
    }
}