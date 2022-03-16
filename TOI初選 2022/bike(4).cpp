#include <iostream>
#include <vector>
#define ll long long
#define pb push_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5+1127;
int n,k;
int W[N];
ll ans;
struct e{int v,w;};
vector<e> G[N];
int dfs(int u,int fa){
    int sum=W[u]-k;
    for(auto [v,w]:G[u]){
        if(v==fa)continue;
        int num=dfs(v,u);
        ans+=abs(num)*w;
        sum+=num;
    }
    return sum;
}
int main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>W[i];
    for(int i=1,u,v,w;i<n;++i){
        cin>>u>>v>>w;
        G[u].pb({v,w});
        G[v].pb({u,w});
    }
    ans=0;
    dfs(1,0);
    cout<<ans;
}

