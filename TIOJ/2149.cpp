#include <iostream>
#include <vector>
#include <queue>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define wiwiho 5208e7
#define pb push_back
#define ll long long
using namespace std;
const int N=1e3+10,K=1030;
const ll INF=8e7*wiwiho;
int n,m,s,t;
struct E{int v,x;ll y;};
struct cmp{bool operator()(E a,E b){return a.y>b.y;}};
vector<E> G[N];
ll dis[N][K];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>s>>t;
	while(m--){
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		G[a].pb({b,x,y});
		G[b].pb({a,x,y});
	}
	fill(&dis[0][0],&dis[N-1][N-1]+1,INF);
	priority_queue<E,vector<E>,cmp> pq;
	pq.push({s,0,0});
	dis[s][0]=0;
	while(!pq.empty()){
		auto [u,x,y]=pq.top();pq.pop();
		if(dis[u][x]<y)continue;
		for(auto [v,a,b]:G[u]){
			if(dis[v][a^x]>dis[u][x]+b){
				dis[v][a^x]=dis[u][x]+b;
				pq.push({v,a^x,dis[v][a^x]});
			}
		}
	}
	if(dis[t][0]==INF)cout<<"-1\n";
	else cout<<dis[t][0];
}
