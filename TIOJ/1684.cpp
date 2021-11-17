#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define pb emplace_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e3+10,M=1e6+10;
int n,m,low[N],vis[N],color[N],cnt;
bool pass[N];
int OG[N][N];
vector<int> G[N];
stack<int> stk;
bool tarjan(int u,int co=1,int fa=-1){
	
	cout<<"Hello"<<endl;
	color[u]=co;
	vis[u]=low[u]=++cnt;
	stk.push(u);
	bool odd=0;
	for(int v:G[u]){
		if(v==fa)continue;
		if(vis[v]){
			low[u]=min(low[u],vis[v]);
			if(co==color[v])odd=1;
		}if(!vis[v]){
			bool tmp=tarjan(v,-co,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=vis[u]){
				int cur;
				do{
					cur=stk.top();stk.pop();
					if(tmp)pass[cur]=1;
				}while(cur!=v);
				if(tmp)pass[u]=1;
			}
			odd|=tmp;
		}
	}
	return odd;
}
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n>>m&&n&&m){
		for(int i=1;i<=n;++i)G[i].clear();
		memset(vis,0,sizeof(vis));
		memset(low,0,sizeof(low));
		memset(color,0,sizeof(color));
		memset(pass,0,sizeof(pass));
		for(int a,b;m;--m){
			cin>>a>>b;
			OG[a][b]=OG[b][a]=1;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j)continue;
				if(!OG[i][j])G[i].pb(j);
			}
		}
		cnt=0;
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				bool tmp=tarjan(i);
				if(tmp)while(!stk.empty())pass[stk.top()]=tmp,stk.pop();
			}
		}
		cnt=0;
		for(int i=1;i<=n;++i)if(!pass[i])cnt++;
		cout<<cnt;
	}
}
