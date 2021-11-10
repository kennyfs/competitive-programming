#include <iostream>
#include <vector>
#include <queue>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
using namespace std;
const int N=1e5+10,MOD=1e9+7;
int n,m,dp[N],deg[N];
queue<int> Q;
vector<int> G[N];
void madd(int &a,int b){
	a=(a+b)%MOD;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
	}
	for(int i=1;i<=n;++i)for(int j:G[i])++deg[j];
	for(int i=1;i<=n;++i)if(!deg[i])Q.push(i);
	dp[1]=1;
	while (!Q.empty()){
		int u=Q.front();Q.pop();
		for(int v:G[u]){
			if(--deg[v]==0)Q.push(v);
			if(dp[u])madd(dp[v],dp[u]);
		}
	}
	cout<<dp[n];
}
