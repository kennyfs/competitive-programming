#include <iostream>
#include <vector>
#define pb emplace_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5+10;
vector<int> G[N];
int n,m;
int team[N];
bool dfs(int cur,int t){
	team[cur]=t;
	for(int nxt:G[cur]){
		if(team[nxt]==t)return 1;
		if(team[nxt])continue;
		if(dfs(nxt,!(t-1)+1))return 1;
	}
	return 0;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		G[u].pb(v);G[v].pb(u);
	}
	for(int i=1;i<=n;++i){
		if(!team[i]&&dfs(i,1)){cout<<"IMPOSSIBLE\n";return 0;}
	}
	for(int i=1;i<=n;++i)cout<<team[i]<<' ';
	cout<<'\n';
}
//judge bipartite graph
