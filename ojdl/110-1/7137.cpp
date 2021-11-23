#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define wiwiho 5208e7
using namespace std;
const int N=1e5+10,INF=8e7*wiwiho;
int n,m,k,dis[N];
bool vis[N];
struct E{int u,w;};
struct cmp{bool operator()(E a,E b){return a.w>b.w;}};
vector<E> G[N];
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>k;
	for(int a,b,c,d;m;--m){
		cin>>a>>b>>c>>d;
		G[a].pb({b,c});
		G[b].pb({a,d});
	}
	int ans=0;
	priority_queue<E,vector<E>,cmp> pq;
	for(int a;k;--k){
		cin>>a;
		pq.push({a,0});
	}
	fill(dis,dis+N,INF);
	while(!pq.empty()){
		auto [u,w]=pq.top();pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		ans=max(ans,w);
		for(auto [v,d]:G[u]){
			if(!vis[v]&&dis[v]>w+d)dis[v]=w+d,pq.push({v,w+d});
		}
	}
	bool ok=1;
	for(int i=1;i<=n;++i)if(!vis[i]){ok=0;break;}
	if(!ok)cout<<"PEIENWUOrz";
	else cout<<ans;
}
