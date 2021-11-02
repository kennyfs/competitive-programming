#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e4+10;
int n,m;
int f[N];
int fa(int me){
    if(f[me]==me)return me;
    return f[me]=fa(f[me]);
}
void join(int a,int b){
    int x=fa(a),y=fa(b);
    if(x==y)return;
    if(x<y)f[y]=x;
    else f[x]=y;
}
int main(){
    Hirasawa_Yui_My_Wife
    while(cin>>n>>m){
        for(int i=1;i<=n;++i)f[i]=i;
        int a,b;
        while(m--){
            cin>>a>>b;
            join(a,b);
        }
        int k;
        cin>>k;
        cout<<fa(k)<<'\n';
    }
}
