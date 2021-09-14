#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5+10;
int n,a[N],q,anc[17][N];
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],anc[0][i]=a[i];
    cin>>q;
    for(int d=1;d<=17;++d){
        for(int i=1;i<=n;++i){
            anc[d][i]=anc[d-1][anc[d-1][i]];
        }
    }
    int a,b;
    while(q--){
        cin>>a>>b;
        int t=0;
        while(b){
            if(b&1)a=anc[t][a];
            ++t;
            b>>=1;
        }
        cout<<a<<'\n';
    }
}
