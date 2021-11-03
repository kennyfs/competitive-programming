#include <iostream>
#include <vector>
#include <cstring>
#define pb emplace_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5+10;
int n,m;
vector<int> G[N],ans;
bool vis[N];
void dfs(int cur){
	vis[cur]=1;
	for(int nxt:G[cur])if(!vis[nxt])dfs(nxt);
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		G[u].pb(v);G[v].pb(u);
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		if(!vis[i])dfs(i),ans.pb(i);
	}
	cout<<ans.size()-1<<'\n';
	for(size_t i=1;i<ans.size();++i){
		cout<<ans[i]<<' '<<ans[i-1]<<'\n';
	}
}
