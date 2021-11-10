#include <iostream>
#include <vector>
#include <queue>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
using namespace std;
const int N=1e5+10;
int n,m,deg[N];
vector<int> G[N],order;
queue<int> Q;
bool vis[N];
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
	for(int i=1;i<=n;++i)if(deg[i]==0)Q.push(i);
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		vis[cur]=1;
		order.pb(cur);
		for(int i:G[cur])if(--deg[i]==0)Q.push(i);
	}
	if(order.size()!=n){cout<<"IMPOSSIBLE";return 0;}
	for(int i:order)cout<<i<<' ';
}
