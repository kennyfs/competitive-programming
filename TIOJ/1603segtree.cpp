#include <iostream>
#define m ((l+r)>>1)
#define INF 8e7*25
#define int long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+10;
int n,q,a[N];
int segmin[4*N],segmax[4*N];
void build(int cur,int l,int r){
    if(l+1==r){segmax[cur]=segmin[cur]=a[l];return;}
    if(l>=r)return;
    build(cur<<1  ,l,m);
    build(cur<<1|1,m,r);
    segmin[cur]=min(segmin[cur<<1],segmin[cur<<1|1]);
    segmax[cur]=max(segmax[cur<<1],segmax[cur<<1|1]);
}
int qmax(int cur,int l,int r,int ql,int qr){
    if(l>=r||r<=ql||qr<=l)return -INF;
    if(ql<=l&&r<=qr)return segmax[cur];
    return max(qmax(cur<<1,l,m,ql,qr),qmax(cur<<1|1,m,r,ql,qr));
}
int qmin(int cur,int l,int r,int ql,int qr){
    if(l>=r||r<=ql||qr<=l)return INF;
    if(ql<=l&&r<=qr)return segmin[cur];
    return min(qmin(cur<<1,l,m,ql,qr),qmin(cur<<1|1,m,r,ql,qr));
}
signed main(){
    Hirasawa_Yui_My_Wife
    fill(segmin,segmin+4*N,INF);
    cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    build(1,1,n+1);
    int l,r;
    while(q--){
        cin>>l>>r;
        if(l>r)swap(l,r);
        cout<<qmax(1,1,n+1,l,r+1)-qmin(1,1,n+1,l,r+1)<<'\n';
    }
}
