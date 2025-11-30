#include<iostream>
#include<vector>
#define NOOFCHAR 256
using namespace std;
void BADCHAR(vector<int>&badchar,string pattern){
    for(int i=0;i<NOOFCHAR;i++){
        badchar[i]=-1;
    }
    for(int i=0;i<pattern.length();i++){
        badchar[(int)pattern[i]]=i;
    }
}
void BAYERMOORE(string text,string pattern){
    int m =pattern.length();
    int n=text.length();
    vector<int>badchar(NOOFCHAR);
    BADCHAR(badchar,pattern);
    int s=0;
    while(s<=n-m){
        int j=m-1;
        while(j>=0 && pattern[j]==text[s+j]) j--;
        if(j<0){
            cout<<"Pattern found at index "<<s<<endl;
            s+=(s+m<n)?m-badchar[(unsigned char)text[s+m]]:1;
        }
        else{
            int shift=max(1,j-badchar[(unsigned char)text[s+j]]);
            s+=shift;
        }
    }
}
int main(){
    string text="ahsiorhfiowhabababa";
    string pattern="ab";
    BAYERMOORE(text,pattern);
}