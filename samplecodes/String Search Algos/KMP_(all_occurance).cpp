#include<iostream>
#include<vector>
using namespace std;
void CalculateLPS(vector<int>&LPS,string pattern){
    int m=pattern.length();
    int pre=0;
    int suf=1;
    while(suf<m){
        if(pattern[pre]==pattern[suf]){
            LPS[suf]=pre+1;
            pre++;
            suf++;
        }
        else{
            if(pre==0){
                LPS[suf]=0;
                suf++;
            }
            else{
                pre=LPS[pre-1];
            }
        }

    }
}
void KMP(string text,string pattern ){
    int m=pattern.length();
    int n=text.length();
    vector<int>LPS(m,0);
    CalculateLPS(LPS,pattern);
    int j=0,i=0;
    while(i<n){
        if(pattern[j]==text[i]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"Pattern found at index "<<i-j<<endl;
          j=LPS[j-1];
        }
        else if(i<n && pattern[j]!=text[i]){
            if(j!=0){
                j=LPS[j-1];
            }
            else{
                i++;
            }
        }

    }

}
int main(){
    string text="ahsiorhfiowhabababa";
    string pattern="ab";
    KMP(text,pattern);
}