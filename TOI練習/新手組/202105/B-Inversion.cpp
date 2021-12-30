#include <iostream>
using namespace std;
const int N=300+10;
string s,ans;
int n;
int main(){
    cin>>s;
    n=s.size();
    int i=0,j=0,tmp;
    for(i=0;i<n;++i){
        if(s[i]=='-'){
            j=i+1;
            while(j<n&&s[j]!='+'&&s[j]!='-')++j;
            --j;
            tmp=j;
            for(;j>i;--j){
                cout<<s[j];
            }
            i=tmp;
        }else if(s[i]!='+'){
            cout<<s[i];
        }
    }
}
