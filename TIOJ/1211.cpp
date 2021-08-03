#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define F first
#define S second
#define pii pair<int,int>
#define pb push_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e4+120,INF=1<<30;
int n,m;
bool vis[N];
vector<pii> G[N];
int dist[N];
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n>>m&&n&&m){
		int u,v,c;
		for(int i=0;i<N;++i)G[i].clear();
		fill(vis,vis+N,0);
		fill(dist,dist+N,INF);
		for(int i=0;i<m;++i){
			cin>>u>>v>>c;
			G[u].pb({c,v});
			G[v].pb({c,u});
		}
		priority_queue<pii,vector<pii>,greater<pii>> pq;
		pq.push({0,1});
		int ans=0;
		dist[1]=0;
		while(!pq.empty()){
			pii cur=pq.top();pq.pop();
			if(vis[cur.S])continue;
			vis[cur.S]=1;
			ans+=cur.F;
			for(pii i:G[cur.S]){
				int w=i.F;
				int v=i.S;
				if(!vis[v]&&dist[v]>w){
					dist[v]=w;
					pq.push({w,v});
				}
			}
		}
		bool flag=0;
		for(int i=1;i<=n;++i)if(!vis[i])flag=1;
		if(flag)cout<<"-1\n";
		else cout<<ans<<'\n';
	}
}
