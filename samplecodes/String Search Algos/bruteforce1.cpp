#include<iostream>
using namespace std;
int BruteForce(string str,string pattern){
    int count=0;
    int n=str.length();
    int m = pattern.length();
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(str[i+j]!=pattern[j]) break;
        }
        if(j==m)    count++;
    }
    return count;
}
int main(){
    string p = "abbababasbdq";
   int count= BruteForce(p,"aba");
    if(count==0)    cout<<"No match found";
    else cout<<"Substring matches "<<count<<" times"<<endl;
}