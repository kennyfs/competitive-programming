#include <iostream>
#include <vector>
#include <queue>
#define wiwiho 5208e7
#define ll long long
#define pb push_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ll INF=8e7*wiwiho;
const int N=1e4+10;
int n,m;
struct E{int v,w;};
vector<E> G[N];
ll dis[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].pb({v,w});
		G[v].pb({u,w});
	}
	queue<int> q;
	q.push(1);
	fill(dis,dis+N,INF);
	dis[1]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto [v,w]:G[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;++i)cout<<dis[i]<<'\n';
}

