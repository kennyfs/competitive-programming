#include <iostream>
#define int long long
#define INF 8e7*25
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+10,K=316;
int n,q,a[N];
int smin[N/K+10],smax[N/K+10];
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>q;
    fill(smin,smin+N/K+10,INF);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        smin[i/K]=min(smin[i/K],a[i]);
        smax[i/K]=max(smax[i/K],a[i]);
    }
    //0 to K-1
    //K to 2K-1
    //...
    int l,r;
    while(q--){
        cin>>l>>r;
        int y,u,mi=INF,ma=0;
        y=l/K;u=r/K;
        if(y==u){
            for(int i=l;i<=r;++i)mi=min(mi,a[i]),ma=max(ma,a[i]);
        }else{
            for(int i=l;i<(y+1)*K;++i){
                mi=min(mi,a[i]);
                ma=max(ma,a[i]);
            }
            for(int i=y+1;i<u;++i){
                mi=min(mi,smin[i]);
                ma=max(ma,smax[i]);
            }
            for(int i=u*K;i<=r;++i){
                mi=min(mi,a[i]);
                ma=max(ma,a[i]);
            }
        }
        cout<<ma-mi<<'\n';
    }
}
