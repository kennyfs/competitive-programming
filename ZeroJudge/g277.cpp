#include <iostream>
#define mid (l+r)>>1
using namespace std;
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int const N=3e5+10;
int n;
int a[N],seg[4*N];
ll pre[N];
void build(int cur,int l,int r){
    if(l>=r)return;
    if(l+1==r){seg[cur]=l;return;}
    build(cur<<1,l,mid);
    build(cur<<1|1,mid,r);
    seg[cur]=(a[seg[cur<<1]]<a[seg[cur<<1|1]])?seg[cur<<1]:seg[cur<<1|1];
}
int query(int cur,int l,int r,int ql,int qr){
    if(l>=r||r<=ql||qr<=l)return -1;
    if(ql<=l&&r<=qr)return seg[cur];
    int le=query(cur<<1,l,mid,ql,qr),ri=query(cur<<1|1,mid,r,ql,qr);
    if(le==-1||ri==-1)return max(le,ri);
    return (a[le]<a[ri])?le:ri;
}
int main(){
    Hirasawa_Yui_My_Wife
    cin>>n;
    pre[0]=0;
    for(int i=1;i<=n;++i)cin>>a[i],pre[i]=pre[i-1]+a[i];
    build(1,1,n+1);
    int l=1,r=n+1,m;//[l,r)
    while(l<r){
        m=query(1,1,n+1,l,r);
        //[l,m-1][m+1,r-1]
        if(pre[m-1]-pre[l-1]<pre[r-1]-pre[m])l=m+1;
        else r=m;
    }
    cout<<a[l]<<'\n';
}
