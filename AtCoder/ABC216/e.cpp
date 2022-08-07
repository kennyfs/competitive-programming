#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define ll long long
using namespace std;
int const N=1e5+10;
int n,k,a[N];
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>k;
    int ma=-1;
    for(int i=0;i<n;++i)cin>>a[i],ma=max(ma,a[i]);
    int L=-1,R=ma,M;//[L,R)
    while(L+1<R){
        M=(L+R)>>1;
        ll K=0;
        bool flag=0;
        for(int i=0;i<n;++i){K+=max(0ll,a[i]-M);if(K>k){flag=1;break;}}
        if(flag)L=M;
        else R=M;
    }
    ll ans=0;
    int added=k;
    for(int i=0;i<n;++i){
        if(a[i]-R>0)ans+=((a[i]+R+1)*(a[i]-R))>>1,added-=a[i]-R;
    }
    ans+=R*added;
    cout<<ans<<'\n';
}
