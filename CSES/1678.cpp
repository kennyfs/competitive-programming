#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb emplace_back
#define wiwiho 5208e7
using namespace std;
const ll INF=8e7*wiwiho;
const int N=1e5+10;
int n,m,pre[N];
vector<int> G[N],ans;
bool vis[N];
stack<int> S;
void output(int u){
	int v=u;
	stack<int> ans;
	ans.push(u);
	do{
		ans.push(v=pre[v]);
	}while(v!=u);
	cout<<ans.size()<<'\n';
	while(!ans.empty())cout<<ans.top()<<' ',ans.pop();
}
bool dfs(int u){//if there's a cycle
	vis[u]=1;
	S.push(u);
	for(int v:G[u]){
		if(vis[v]==1){
			cout<<"v="<<v<<endl;
			ans.pb(v);
			while(S.top()!=v)cout<<S.top()<<endl,ans.pb(S.top()),S.pop();
			ans.pb(v);
			return 1;
		}
		if(!vis[v])if(dfs(v))return 1;
	}
	S.pop();
	vis[u]=2;
	return 0;
}
int main(){
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
	}
	int u;
	for(int i=1;i<=n;++i)
		if(!vis[i]&&(u=dfs(i))){
			reverse(ans.begin(),ans.end());
			cout<<ans.size()<<'\n';
			for(int i:ans)cout<<i<<' ';
			return 0;
		}
	cout<<"IMPOSSIBLE";
}
