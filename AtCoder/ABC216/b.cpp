#include <iostream>
using namespace std;
int const N=1010;
string s[N],t[N];
int n;
int main(){
    cin>>n;
    bool flag=0;
    for(int i=0;i<n;++i){
        cin>>s[i]>>t[i];
        for(int j=0;j<i;++j)if(s[i]==s[j]&&t[i]==t[j]){cout<<"Yes\n",flag=1;break;}
        if(flag)break;
    }
    if(!flag)cout<<"No\n";
}
