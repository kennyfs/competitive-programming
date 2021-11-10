#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
using namespace std;
const int N=1e5+10;
int n,m,deg[N],dp[N],nxt[N];//dp[i]:i to n route is at most dp[i] nodes
vector<int> G[N],order;
queue<int> Q;
void output(int u){
	if(u==1){
		if(dp[1])cout<<dp[1]<<'\n';
		else{cout<<"IMPOSSIBLE";return;}
	}
	cout<<u<<' ';
	if(u!=n)output(nxt[u]);
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
	}
	//topological sort
	for(int i=1;i<=n;++i)for(int j:G[i])++deg[j];
	for(int i=1;i<=n;++i)if(!deg[i])Q.push(i);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		order.pb(u);
		for(int v:G[u])if(--deg[v]==0)Q.push(v);
	}
	reverse(order.begin(),order.end());
	dp[n]=1;
	for(int u:order){
		for(int v:G[u]){
			if(!dp[v])continue;
			if(dp[u]<dp[v]+1){
				dp[u]=dp[v]+1;
				nxt[u]=v;
			}
		}
	}
	output(1);
}
