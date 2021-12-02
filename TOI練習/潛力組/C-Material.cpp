#include <iostream>
#include <algorithm>
using namespace std;
const int N=4e5+10;
int n,q;
int M[N],bit[N],last[N];
struct Q{
    int l,r,t;
}qu[N];
void mod(int pos,int v){
    for(;pos<=n;pos+=pos&-pos){
        bit[pos]+=v;
    }
}
int query(int pos){
    int ans=0;
    for(;pos;pos-=pos&-pos){
        ans+=bit[pos];
    }
    return ans;
}
int ans[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>M[i];
    cin>>q;
    for(int i=0;i<q;++i)cin>>qu[i].l>>qu[i].r,qu[i].t=i;
    sort(qu,qu+q,[&](Q a,Q b){return a.r<b.r;});
    int cur=0;
    for(int i=1;i<=n;++i){
        if(last[M[i]])mod(last[M[i]],-1);
        last[M[i]]=i;
        mod(i,1);
        while(cur<q&&qu[cur].r<=i){
            ans[qu[cur].t]=query(qu[cur].r)-query(qu[cur].l-1);
            ++cur;
        }
    }
    for(int i=0;i<q;++i)cout<<ans[i]<<'\n';
}
