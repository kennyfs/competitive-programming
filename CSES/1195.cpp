#include <iostream>
#include <vector>
#include <queue>
#define wiwiho 5208e7
#define ll long long
#define pb push_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ll INF=8e7*wiwiho;
const int N=1e5+10;
struct E{int v,w;};
struct Spq{int u;ll w;bool c;};
vector<E> G[N];
struct cmp{bool operator()(Spq a,Spq b){return a.w>b.w;}};
ll dis[N],cdis[N];//dis: normal, cvis: dis with coupon
bool vis[N],cvis[N];
int n,m;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].pb({v,w});
	}
	fill(dis,dis+N,INF);fill(cdis,cdis+N,INF);
	dis[1]=cdis[1]=0;
	priority_queue<Spq,vector<Spq>,cmp> pq;
	pq.push({1,0,0});
	while(!pq.empty()){
		Spq cur=pq.top();pq.pop();
		if(cur.c){
			if(cvis[cur.u])continue;
			cvis[cur.u]=1;
			cdis[cur.u]=cur.w;
			for(auto [v,w]:G[cur.u]){
				if(cdis[v]>cur.w+w){
					pq.push({v,cur.w+w,1});
					cdis[v]=cur.w+w;
				}
			}
		}else{
			if(vis[cur.u])continue;
			vis[cur.u]=1;
			dis[cur.u]=cur.w;
			for(auto [v,w]:G[cur.u]){
				if(dis[v]>cur.w+w){
					pq.push({v,cur.w+w,0});
					dis[v]=cur.w+w;
				}
				if(cdis[v]>cur.w+(w>>1)){
					pq.push({v,cur.w+(w>>1),1});
					cdis[v]=cur.w+(w>>1);
				}
			}
		}
	}
	cout<<min(dis[n],cdis[n]);
}
