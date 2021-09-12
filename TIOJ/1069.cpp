#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma loop_opt(on)
#include <iostream>
#include <cstring>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1000+10;
int t,n;
struct event{
	int t,x,y;
	inline bool operator==(event& o)const{//a==b means I can do a then b
		if(t>=o.t)return 0;
		return (o.t-t)>=(abs(x-o.x)+abs(y-o.y));
	}
} e[N];
int mx[N],my[N];
bool adj[N][N],vis[N];
bool dfs(int u){
	if(vis[u])return 0;
	vis[u]=1;
	for(int v=0;v<n;++v){if(!adj[u][v])continue;
		if(my[v]==-1||dfs(my[v])){
			mx[u]=v;my[v]=u;
			return 1;
		}
	}
	return 0;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>e[i].t>>e[i].x>>e[i].y;
		memset(adj,0,sizeof(adj));
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(e[i]==e[j])adj[i][j]=1;
			}
		}
		fill(mx,mx+N,-1);
		fill(my,my+N,-1);
		for(int i=0;i<n;++i){
			memset(vis,0,sizeof(vis));
			dfs(i);
		}
		int cnt=0;
		for(int i=0;i<n;++i){
			if(mx[i]==-1&&my[i]!=-1)++cnt;
			else if(mx[i]==-1&&my[i]==-1)++cnt;
		}
		cout<<cnt<<'\n';
	}
}
//二分圖匹配
