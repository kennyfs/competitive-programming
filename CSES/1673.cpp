#include <iostream>
#include <vector>
#include <queue>
#define pb push_back
#define wiwiho 5208e7
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2.5e3+10;
const ll INF=8e7*wiwiho;
int n,m;
struct E{int v,w;};
struct qitem{int v,t;};
vector<E> G[N];
vector<int> B[N];
queue<qitem> Q;
ll dis[N];
bool dvis[N],bvis[N];
void dfs(int u){
	dvis[u]=1;
	for(auto [v,w]:G[u]){
		if(!dvis[v])dfs(v);
	}
}
void bdfs(int u){
	bvis[u]=1;
	for(int v:B[u]){
		if(!bvis[v])bdfs(v);
	}
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int u,v,c;
		cin>>u>>v>>c;
		G[u].pb({v,-c});
		B[v].pb(u);
	}
	dfs(1);
	bdfs(n);
	fill(dis,dis+N,INF);
	Q.push({1,0});
	dis[1]=0;
	while(!Q.empty()){
		qitem u=Q.front();Q.pop();
		if(u.t>n)break;
		for(auto [v,w]:G[u.v]){
			if(dis[u.v]+w<dis[v]){
				if(u.t>=n&&dvis[v]&&bvis[v]){cout<<"-1\n";return 0;}
				dis[v]=dis[u.v]+w;
				Q.push({v,u.t+1});
			}
		}
	}
	cout<<-dis[n]<<'\n';
}
