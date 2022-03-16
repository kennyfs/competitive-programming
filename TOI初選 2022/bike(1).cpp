#include <iostream>
#include <vector>
#define pb push_back
#define int long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5;
int n,k;
int W[N];
struct e{int v,w;};
vector<e> G[N];
int dis[N];
void dfs(int u,int fa){
    for(auto [v,w]:G[u]){
        if(v==fa)continue;
        dis[v]=dis[u]+w;
        dfs(v,u);
    }
}
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>k;
    int top=-1,cnt=0;
    for(int i=1;i<=n;++i){
        cin>>W[i];
        if(W[i]>k)top=i,cnt++;
        if(cnt>1)return 1;
    }
    for(int i=1,u,v,w;i<n;++i){
        cin>>u>>v>>w;
        G[u].pb({v,w});
        G[v].pb({u,w});
    }
    dfs(top,-1);
    int ans=0;
    for(int i=1;i<=n;++i)
        if(W[i]<k)ans+=dis[i]*(k-W[i]);
    cout<<ans;
}
