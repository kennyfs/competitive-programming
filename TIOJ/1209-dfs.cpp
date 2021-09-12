#include <iostream>
#include <vector>
#include <cstring>
#define pb emplace_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=4e4+10;
int n,m;
vector<int> G[N];
int test[N];
bool dfs(int cur,int co){
	test[cur]=co;
	for(int j=0;j<G[cur].size();++j){
		int v=G[cur][j];
		if(test[v]==0){
			if(dfs(v,-co))return 1;
		}else{
			if(test[v]==co)return 1;
		}
	}
	return 0;
}
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		for(int i=0;i<=n+5;++i)G[i].clear();
		int u,v;
		while(m--){
			cin>>u>>v;
			G[u].pb(v);
			G[v].pb(u);
		}
		memset(test,0,sizeof(test));
		bool flag=0;
		for(int i=1;i<=n;++i){
			if(!test[i]&&dfs(1,7122)){cout<<"No\n";flag=1;break;}
		}
		if(!flag)cout<<"Yes\n";
	}
}
//dfs
