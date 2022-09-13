#include <iostream>
using namespace std;
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define wiwiho 5208e7
const int N=1e6+520,inf=8e7*wiwiho;
int n,q,rc[N],lc[N],p,t,f[N],cnt;
int fo[N],mo[N],lo[N];
int fi=1,mi=1,li=1;
bool ok[N];
void fdfs(int cur){
    if(cur==0)return;
    fo[fi++]=cur;
    fdfs(lc[cur]);
    fdfs(rc[cur]);
}
void mdfs(int cur){
    if(cur==0)return;
    mdfs(lc[cur]);
    mo[mi++]=cur;
    mdfs(rc[cur]);
}
void ldfs(int cur){
    if(cur==0)return;
    ldfs(lc[cur]);
    ldfs(rc[cur]);
    lo[li++]=cur;
}

int fa(int cur){
    if(f[cur]==cur)return cur;
    return f[cur]=fa(f[cur]);
}
void join(int a,int b){
    if(fa(a)==fa(b))return;
    cnt-=1;
    f[fa(a)]=fa(b);
}
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>q;
    for(int i=1;i<=n;++i)f[i]=i;
    for(int i=2;i<=n;++i){
        cin>>p>>t;
        if(t==0){
            lc[p]=i;
        }else{
            rc[p]=i;
        }
    }
    fdfs(1);
    mdfs(1);
    ldfs(1);
    cnt=n;
    /*
    for(int i=1;i<=n;++i)cout<<fa(i)<<' ';
    cout<<'\n';
    join(1,2);
    for(int i=1;i<=n;++i)cout<<fa(i)<<' ';
    cout<<'\n';
    join(3,2);
    for(int i=1;i<=n;++i)cout<<fa(i)<<' ';
    cout<<'\n';
    return 0;*/
    for(int i=1;i<=n/2+1;++i)join(fo[i],fo[n-i+1]);
    for(int i=1;i<=n/2+1;++i)join(mo[i],mo[n-i+1]);
    for(int i=1;i<=n/2+1;++i)join(lo[i],lo[n-i+1]);
    cout<<cnt<<'\n';
    for(int i=1;i<=q;++i){
        int u,v;
        cin>>u>>v;
        join(u,v);
        cout<<cnt<<'\n';
    }
}
