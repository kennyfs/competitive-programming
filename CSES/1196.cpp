#include <iostream>
#include <vector>
#include <queue>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define wiwiho 5208e7
#define ll long long
using namespace std;
const int N=1e5+10;
const ll INF=8e7*wiwiho;
struct E{int v;ll w;};
struct cmp{bool operator()(E a,E b){return a.w>b.w;}};
vector<E> G[N];
int n,m,k;
int vis[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].pb({v,w});
	}
	//dijkstra from 1 to n, and visits each node at most k times
	priority_queue<E,vector<E>,cmp> pq;
	pq.push({1,0});
	while(!pq.empty()){
		auto [u,d]=pq.top();pq.pop();
		if(vis[u]>=k)continue;
		if(u==n)cout<<d<<' ';
		vis[u]++;
		for(auto [v,w]:G[u])pq.push({v,d+w});
	}
}
