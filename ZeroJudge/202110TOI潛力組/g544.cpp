#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,k;
const int N=1e6+10;
int s[N],w[N];
int main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>s[i];
    for(int i=1;i<=n;++i)cin>>w[i];
    int mx=0;
    int ans=0;
    for(int i=1;i<=n;++i){
        if(w[i]!=w[i-1])ans+=mx,mx=s[i];
        else mx=max(mx,s[i]);
    }
    ans+=mx;
    cout<<ans<<'\n';
}
