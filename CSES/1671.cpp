#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pll pair<ll,ll>
#define F first
#define S second
#define pb push_back
#define wiwiho 52080000000
using namespace std;
const ll INF=8e7*wiwiho;
const int N=1e5+10;
vector<pll> G[N];
priority_queue<pll,vector<pll>,greater<pll>> pq;
ll dis[N];
int n,m;
bool vis[N];
int main(){
	Hirasawa_Yui_My_Wife
    cin>>n>>m;
    while(m--){
        int u;
        ll v,w;
        cin>>u>>v>>w;
        G[u].pb({v,w});
    }
    fill(dis,dis+n+1,INF);
    dis[1]=0;
    pq.push({0,1});
    pll cur;
    //Dijkstra，從1開始
    while(!pq.empty()){
        cur=pq.top();pq.pop();
        if(vis[cur.S])continue;
        dis[cur.S]=cur.F;
        vis[cur.S]=1;
        for(auto [v,w]:G[cur.S]){
            pq.push({cur.F+w,v});
        }
    }
    for(int i=1;i<=n;++i)cout<<dis[i]<<' ';
}
