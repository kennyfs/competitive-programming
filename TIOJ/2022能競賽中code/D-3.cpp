#include <iostream>
#include <algorithm>
using namespace std;
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define wiwiho 5208e7
const int N=2e6+520,sN=3e3+10,inf=8e7*wiwiho;
int n,k,a[N],pre[N],oki[N],okpre[N];
bool ok[N];
int segmax[4*N];
int query(int cur,int l,int r,int ql,int qr){
    if(l>=r||r<=ql||qr<=l)return -inf;
    if(ql<=l&&r<=qr)return segmax[cur];
    int m=l+r>>1;
    return max(query(cur<<1,l,m,ql,qr),query(cur<<1|1,m,r,ql,qr));
}
void build(int cur,int l,int r){
    if(r-l==1){segmax[cur]=pre[l];return;}
    int m=l+r>>1;
    build(cur<<1,l,m);
    build(cur<<1|1,m,r);
    segmax[cur]=max(segmax[cur<<1],segmax[cur<<1|1]);
}
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>k;
    okpre[0]=0;
    int cur=0;
    for(int i=1;i<=n;++i){
        char c;
        cin>>c;
        ok[i]=(c=='1');
        okpre[i]=okpre[i-1];
        if(ok[i]){
            okpre[i]++;
            oki[++cur]=i;
        }
    }
    while(cur<n+k+10)oki[++cur]=n+1;
    pre[0]=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    build(1,1,n+1);
    int ans=0;
    for(int st=1;st<=n;st++){
        int ed=oki[okpre[st]+k+1]-1;
        int mx=query(1,1,n+1,st,ed+1);
        mx-=pre[st-1];
        if(mx>ans)ans=mx;
    }
    cout<<ans;
}
