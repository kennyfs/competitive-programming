#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,k;
string s[4];
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>k;
    for(int i=1;i<=k;++i)cin>>s[i];
    for(int i=0,z,o;i<n;++i){
        z=0,o=0;
        for(int j=1;j<=k;++j){if(s[j][i]=='1')++o;else ++z;}
        if(o>z)cout<<'0';
        else cout<<'1';
    }
}
