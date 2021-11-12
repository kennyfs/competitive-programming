#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
using namespace std;
const int N=1e6+10;
int n,m,low[N],scc[N],vis[N],ssz[N],deg[N],dp[N],tot=1,scctot=1;
bool ins[N];
vector<int> G[N],sG[N];
stack<int> stk;
queue<int> Q;
void dfs(int u){
	low[u]=vis[u]=tot++;
	ins[u]=1;
	stk.push(u);
	for(int v:G[u]){
		if(!vis[v])dfs(v);
		if(ins[v])low[u]=min(low[u],low[v]);
	}
	if(low[u]==vis[u]){
		int cur;
		do{
			cur=stk.top();stk.pop();
			ins[cur]=0;
			scc[cur]=scctot;
			++ssz[scctot];
		}while(cur!=u);
		++scctot;
	}
}
int main(){
	Hirasawa_Yui_My_Wife
	tot=1,scctot=1;
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;++u,++v;
		G[u].pb(v);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i])dfs(i);
	}
	--scctot;
	for(int i=1;i<=n;++i){
		for(int j:G[i]){
			if(scc[i]!=scc[j]){
				sG[scc[i]].pb(scc[j]);
			}
		}
	}
	for(int i=1;i<=scctot;++i)for(int j:sG[i])deg[j]++;
	for(int i=1;i<=scctot;++i)if(deg[i]==0)Q.push(i),dp[i]=ssz[i];
	int ans=0;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		ans=max(ans,dp[u]);
		for(int v:sG[u]){
			dp[v]=max(dp[v],dp[u]+ssz[v]);
			if(--deg[v]==0)Q.push(v);
		}
	}
	cout<<ans;
}
//第一次寫SCC縮點+DAG DP，讚啦
