#include <iostream>
#define ll long long
#define wiwiho 5208e7
using namespace std;
const ll INF=8e7*wiwiho;
const int N=5e2+10;
int n,m;
ll dis[N][N];
void chmin(ll &a,ll b){
	a=min(a,b);
}
int main(){
	cin>>n>>m;
	fill(&dis[0][0],&dis[N-1][N-1]+1,INF);
	for(int i=1;i<=n;++i)dis[i][i]=0;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		chmin(dis[u][v],w);
		chmin(dis[v][u],w);
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	cin>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		if(dis[u][v]!=INF){
			cout<<dis[u][v]<<'\n';
		}else cout<<"-1\n";
	}
}
