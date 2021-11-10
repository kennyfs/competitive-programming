#include <iostream>
#include <vector>
#include <queue>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define wiwiho 5208e7
#define pb push_back
#define ll long long
using namespace std;
const int N=1e5+10,MOD=1e9+7;
const ll INF=8e7*wiwiho;
int n,m,dp[N],mi[N],mx[N];
struct E{int v;ll w;};
struct cmp{bool operator()(E a,E b){return a.w>b.w;}};
vector<E> G[N];
ll dis[N];
queue<int> Q;
void madd(int &a,int b){a=(a+b)%MOD;}
void chmin(int &a,int b){a=min(a,b);}
void chmax(int &a,int b){a=max(a,b);}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].pb({v,w});
	}
	priority_queue<E,vector<E>,cmp> pq;
	pq.push({1,0});
	fill(dis,dis+N,INF);
	dis[1]=mi[1]=mx[1]=0;
	dp[1]=1;
	while(!pq.empty()){
		auto [u,d]=pq.top();pq.pop();
		if(dis[u]<d)continue;
		for(auto [v,w]:G[u]){
			if(dis[v]>d+w){//可以鬆弛
				dis[v]=d+w;
				pq.push({v,dis[v]});
				dp[v]=dp[u];
				mi[v]=mi[u]+1;
				mx[v]=mx[u]+1;
			}else if(dis[v]==d+w){
				madd(dp[v],dp[u]);
				chmin(mi[v],mi[u]+1);
				chmax(mx[v],mx[u]+1);
			}
		}
	}
	cout<<dis[n]<<' '<<dp[n]<<' '<<mi[n]<<' '<<mx[n];
}
