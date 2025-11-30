#include<iostream>
using namespace std;
void MergeTwoArary(int arr[],int start,int end){
    int mid = start+ (end-start)/2;
    int len1 = mid-start+1;
    int len2 = end - mid;
    int *leftarr = new int[len1];
    int *rightarr= new int[len2];
    int k = start;
    for(int i=0;i<len1;i++){
        leftarr[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++){
        rightarr[i]=arr[k++];
    }

     k = start;
    int index1=0;
    int index2 =0;
    while(index1<len1 && index2<len2){
        if(leftarr[index1]<rightarr[index2]){
            arr[k++]=leftarr[index1++];
        }
        else{
            arr[k++]=rightarr[index2++];
        }
    }
    while(index1<len1){
        arr[k++]=leftarr[index1++];
    }
    while(index2<len2){
        arr[k++]=rightarr[index2++];
    }
}
void MergeSort(int arr[],int start,int end){
    if(start>=end){
        return;
    }

    int mid=start+ (end-start)/2;
    MergeSort(arr,start,mid);
    MergeSort(arr,mid+1,end);
    MergeTwoArary(arr,start,end);
}
int main(){
    int arr[]={100,23,22,11,32,1,2,6,5,4};
    MergeSort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}