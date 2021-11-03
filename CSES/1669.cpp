#include <iostream>
#include <vector>
#include <queue>
#define pb emplace_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+10;
int n,m,du[N];
vector<int> G[N],ans;
int P[N];
void dfs(int cur,int fa){
	for(int i:G[cur]){
		if(i==fa)continue;
		if(P[i]){
			//output answer
			ans.pb(cur);
			while(ans.back()!=i){
				ans.pb(P[ans.back()]);
			}
			ans.pb(cur);
			cout<<ans.size()<<'\n';
			for(int j:ans)cout<<j<<' ';
			exit(0);
		}
		P[i]=cur;
		dfs(i,cur);
	}
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
		if(!P[i])P[i]=i,dfs(i,0);
	}
	cout<<"IMPOSSIBLE\n";
}
