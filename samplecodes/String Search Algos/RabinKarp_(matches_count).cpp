#include<iostream>
using namespace std;
int RabinKarp(string str, string pattern){
    int n=str.length();
    int m =pattern.length();
    int count =0;
    if(m>n){
        cout<<"Invalid pattern to search"<<endl;
        return 0;
    }
    int d=256;
    int q=11;
    int h=1;
    int p_hash=0;
    int t_hash=0;
    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }
    for(int i=0;i<m;i++){
        p_hash=(p_hash*d+pattern[i])%q;
        t_hash=(t_hash*d+str[i])%q;
    }
    for(int i=0;i<=n-m;i++){
        if(p_hash==t_hash){
            int j=0;
            for(j=0;j<m;j++){
                if(str[i+j]!=pattern[j])
                break;
            }
            if(j==m){
                count++;
            }
        }
        
        if(i<n-m){
            t_hash=(d*(t_hash-h*str[i])+str[i+m])%q;
            if(t_hash<0)    t_hash+=q;
        }
    }
    return count;
}
int main(){
    string str = "ababababbahoiwehfh";
    string pattern = "ab";
    int count=RabinKarp(str,pattern);
      if(count==0)    cout<<"No match found";
    else cout<<"Substring matches "<<count<<" times"<<endl;
}