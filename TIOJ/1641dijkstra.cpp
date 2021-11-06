#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <iomanip>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define pif pair<int,double>
#define pfi pair<double,int>
#define F first
#define S second
#define wiwiho 13145208e7
using namespace std;
const double INF=8e7*wiwiho;
const int N=1e4+10;
int n,m,s,t;
vector<pif> G[N];
struct cmp{
	bool operator()(pfi a,pfi b){return a.F>b.F;}
};
priority_queue<pfi,vector<pfi>,cmp>pq;
double dis[N];
bool vis[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>s>>t;
	while(m--){
		int u,v;
		double w;
		cin>>u>>v>>w;
		G[u].pb({v,log10(w+1)});
	}
	fill(dis,dis+N,INF);
	pfi cur;
	pq.push({0,s});
	while(!pq.empty()){
		cur=pq.top();pq.pop();
		if(vis[cur.S])continue;
		vis[cur.S]=1;
		dis[cur.S]=cur.F;
		if(cur.S==t)break;
		for(auto [v,d]:G[cur.S]){
			if(dis[v]>cur.F+d){
				dis[v]=cur.F+d;
				pq.push({cur.F+d,v});
			}
		}
	}
	double ans,tmp;
	ans=modf(dis[t],&tmp);
	int fst=tmp;
	cout<<fixed<<setprecision(2)<<pow(10,ans)<<"e+";
	cout<<fst/100;fst%=100;
	cout<<fst/10;fst%=10;
	cout<<fst;
}
