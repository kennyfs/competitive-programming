#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=800+10,M=10000+10;
int n,m;
int a,b;
vector<int> G[N];
bool vis[N];
bool dfs(int c){
	vis[c]=1;
	if(c==b)return 1;
	for(int i:G[c]){
		if(vis[i])continue;
		if(dfs(i))return 1;
	}
	return 0;
}
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n>>m){
		for(int i=1;i<=n;++i){G[i].clear();vis[i]=0;}
		int u,v;
		while(m--){
			cin>>u>>v;
			G[u].push_back(v);
		}
		cin>>a>>b;
		if(dfs(a)){
			cout<<"Yes!!!\n";
		}else{
			cout<<"No!!!\n";
		}
	}
}
//圖論裸dfs水題
