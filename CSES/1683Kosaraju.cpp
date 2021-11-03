#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define pb emplace_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5+10;
int n,m;
vector<int> G[N],NG[N];
bool vis[N];
stack<int> order;
void normal_dfs(int cur){
	vis[cur]=1;
	for(int nxt:G[cur])if(!vis[nxt])normal_dfs(nxt);
	order.push(cur);
}
int team[N];
void back_dfs(int cur,int t){
	vis[cur]=1;
	team[cur]=t;
	for(int nxt:NG[cur])if(!vis[nxt])back_dfs(nxt,t);
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		G[u].pb(v);NG[v].pb(u);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i])normal_dfs(i);
	}
	int tot=1;
	memset(vis,0,sizeof(vis));
	while(!order.empty()){
		int cur=order.top();order.pop();
		if(vis[cur])continue;
		back_dfs(cur,tot++);
	}
	cout<<--tot<<'\n';
	for(int i=1;i<=n;++i)cout<<team[i]<<' ';
	cout<<'\n';
}
