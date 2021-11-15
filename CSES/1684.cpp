#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
#define push emplace
using namespace std;
const int N=1e5+10;
int n,m,cnt,scctot,low[2*N],vis[2*N],scc[2*N],ans[N],deg[2*N];
vector<int> G[2*N],sG[2*N],C[2*N];
stack<int> stk;
auto chmin=[](int &a,int b){a=min(a,b);};
void dfs(int u){
	vis[u]=low[u]=++cnt;
	stk.push(u);
	for(int v:G[u]){
		if(!vis[v]){
			dfs(v);
			chmin(low[u],low[v]);
		}else if(!scc[v])
			chmin(low[u],vis[v]);
	}
	if(low[u]==vis[u]){
		int cur;
		++scctot;
		do{
			cur=stk.top();stk.pop();
			scc[cur]=scctot;
		}while(cur!=u);
	}
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>m>>n;
	char a,c;int b,d;
	while(m--){
		cin>>a>>b>>c>>d;
		b=(b<<1)+(a=='-');d=(d<<1)+(c=='-');
		//2a  :a good
		//2a+1:a bad
		//not b -> d
		G[b^1].pb(d);
		//not d -> b
		G[d^1].pb(b);
	}
	//1~n -> 2~2n+1
	for(int i=2;i<=(n<<1|1);++i)if(!vis[i])dfs(i);
	for(int i=1;i<=n;++i){
		if(scc[i<<1]==scc[i<<1|1]){
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
	//connect edge of scc
	for(int i=2;i<=(n<<1|1);++i){
		C[scc[i]].pb(i);
		for(int j:G[i]){
			if(scc[i]==scc[j])continue;
			sG[scc[i]].pb(scc[j]);
			++deg[scc[j]];
		}
	}
	//topological sort
	//scc 1~scctot
	queue<int> Q;
	stack<int> ord;
	for(int i=1;i<=scctot;++i)if(deg[i]==0)Q.push(i);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		ord.push(u);
		for(int v:sG[u]){
			if(--deg[v]==0)Q.push(v);
		}
	}
	memset(vis,0,sizeof(vis));
	while(!ord.empty()){
		int u=ord.top();ord.pop();
		bool ok=1;
		for(int i:C[u])if(vis[i>>1]){ok=0;break;}
		if(!ok)continue;
		for(int i:C[u]){
			ans[i>>1]=i&1;
			vis[i>>1]=1;
		}
	}
	//output ans
	for(int i=1;i<=n;++i)
		cout<<(ans[i]?'-':'+')<<' ';
}
