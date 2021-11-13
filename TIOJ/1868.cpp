#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
using namespace std;
const int N=3e5+10;
int n,k,a[N],scc[N],ssz[N],deg[N],vis[N],low[N],dp[N],cnt,scctot=1;
vector<int> G[N],rsG[N];
stack<int> stk;
bool instack[N];
void dfs(int u){
	vis[u]=low[u]=++cnt;
	instack[u]=1;
	stk.push(u);
	for(int v:G[u]){
		if(!vis[v])dfs(v);
		if(instack[v])low[u]=min(low[u],low[v]);
	}
	if(low[u]==vis[u]){
		int cur;
		do{
			cur=stk.top();stk.pop();
			instack[cur]=0;
			if(cur!=0)++ssz[scctot];
			scc[cur]=scctot;
		}while(cur!=u);
		++scctot;
	}
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		if(i+1<=n&&a[i]>=a[i+1])G[i].pb(i+1);
		if(i-1>=1&&a[i]>=a[i-1])G[i].pb(i-1);
		G[0].pb(i);
	}
	string s;
	getline(cin,s);
	getline(cin,s);
	for(int i=0;i<n;++i)if(s[i]=='T')G[i+1].pb(0);
	cnt=0;
	for(int i=0;i<=n;++i)if(!vis[i])dfs(i);
	--scctot;
	for(int i=0;i<=n;++i)for(int j:G[i])if((ssz[scc[0]]!=1||j!=0)&&scc[i]!=scc[j])rsG[scc[j]].pb(scc[i]),++deg[scc[i]];
	queue<int> Q;
	for(int i=1;i<=scctot;++i)if(deg[i]==0)Q.push(i),dp[i]=ssz[i];
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int v:rsG[u]){
			dp[v]=max(dp[v],dp[u]+ssz[v]);
			if(--deg[v]==0)Q.push(v);
		}
	}
	cout<<dp[scc[k]];
}
