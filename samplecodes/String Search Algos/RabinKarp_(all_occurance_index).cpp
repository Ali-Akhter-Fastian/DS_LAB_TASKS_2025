#include<iostream>
using namespace std;
void RabinKarp(string str, string pattern){
    int n=str.length();
    int m = pattern.length();
    if(m>n){
        cout<<"Invalid pattern, can't serach"<<endl;
        return;
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
                cout<<"Pattern found at index "<<i<<"."<<endl;
            }
        }
        if(i<n-m){
            t_hash=(d*(t_hash-h*str[i])+str[i+m])%q;
            if(t_hash<0)    t_hash+=q;
        }
    }
    return;

}
int main(){
    string str = "ababababbahoiwehfh";
    string pattern = "ab";
   RabinKarp(str,pattern);
}