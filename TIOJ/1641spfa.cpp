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
#define push emplace
using namespace std;
const double INF=8e7*wiwiho;
const int N=1e4+10;
int n,m,s,t;
vector<pif> G[N];
struct cmp{
	bool operator()(pfi a,pfi b){return a.F>b.F;}
};
double dis[N];
bool inq[N];
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
	dis[s]=0;
	int cur;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		cur=q.front();q.pop();
		inq[cur]=0;
		for(auto [v,d]:G[cur]){
			if(dis[v]>dis[cur]+d){
				dis[v]=dis[cur]+d;
				if(!inq[v])q.push(v),inq[v]=1;
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
