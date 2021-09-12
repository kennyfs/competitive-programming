#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma loop_opt(on)
#include <cstdio>
#include <vector>
#include <cstring>
#define Hirasawa_Yui_My_Wife
#define pb emplace_back
using namespace std;
int const N=1000+10,K=20000+10;
int n,k,mx[N],my[N];
vector<int> adj[N];
bool vis[N];
bool dfs(int u){
	if(vis[u])return 0;
	vis[u]=1;
	for(int v:adj[u]){
		if(!my[v]||dfs(my[v])){
			mx[u]=v;my[v]=u;
			return 1;
		}
	}
	return 0;
}
const int S = 1<<20;
inline char readchar(){
	static char buf[S], *p = buf, *q = buf;
	return (p==q&&(q=(p=buf)+fread(buf,1,S,stdin))==buf) ? EOF : *p++;
}
inline int R(){
	int ans = 0, c = readchar(), minus = false;
	while((c<'0'||c>'9')&&c!='-'&&c!=EOF) c=readchar();
	if(c=='-') minus = true, c = readchar();
	while(c>='0'&&c<='9') ans=(ans<<3)+(ans<<1)+(c^'0'), c=readchar();
	return minus ? -ans : ans;
}
int main(){
	Hirasawa_Yui_My_Wife
	int t=1;
	while(n=R(),k=R(),n&&k){
		memset(adj,0,sizeof(adj));
		int x,y;
		for(int i=0;i<k;++i){
			x=R();y=R();
			adj[x].pb(y);
		}
		memset(mx,0,sizeof(mx));
		memset(my,0,sizeof(my));
		int cnt=0;
		for(int i=1;i<=n;++i){
			memset(vis,0,sizeof(vis));
			if(dfs(i))++cnt;
		}
		printf("Case #%d:%d\n",t++,cnt);
	}
}
//二分圖匹配
