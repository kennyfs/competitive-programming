#include <iostream>
#include <vector>
#include <queue>
#define wiwiho 25
#define pb push_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int INF=8e7*wiwiho;
const int N=1e4+10;
int n,m;
struct E{int v,w;};
struct qitem{int v,t;};
vector<E> G[N];
int dis[N];
bool inq[N],vis[N];
void spfa(int s){
	queue<qitem> q;
	q.push({s,0});
	fill(dis,dis+N,INF);
	fill(inq,inq+N,0);
	dis[s]=0;
	while(!q.empty()){
		qitem u=q.front();q.pop();
		vis[u.v]=1;
		if(u.t>=n){cout<<"YES";exit(0);}
		inq[u.v]=0;
		for(auto [v,w]:G[u.v]){
			if(dis[v]>dis[u.v]+w){
				dis[v]=dis[u.v]+w;
				if(!inq[v])q.push({v,u.t+1}),inq[v]=1;
			}
		}
	}
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].pb({v,w});
	}
	for(int i=1;i<=n;++i)if(!vis[i])spfa(i);
	cout<<"NO";
}

