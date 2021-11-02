#include <iostream>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,q;
ll bit[N],a[N];
void add(int pos,int v){
    for(;pos<=n;pos+=pos&-pos)bit[pos]+=v;
}
ll Q(int pos){
    ll ans=0;
    for(;pos;pos-=pos&-pos)ans+=bit[pos];
    return ans;
}
int main(){
    cin>>n>>q;
    cin>>a[1];add(1,a[1]);
    for(int i=2;i<=n;++i)cin>>a[i],add(i,a[i]-a[i-1]);
    int op,a,b,u,k;
    while(q--){
        cin>>op;
        switch(op){
        case 1:
            cin>>a>>b>>u;
            add(a,u);add(b+1,-u);
            break;
        case 2:
            cin>>k;
            cout<<Q(k)<<'\n';
        }
    }
}
