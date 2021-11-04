#include <iostream>
#include <vector>
#define wiwiho 5208e7
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
struct E{
	int v,w;
};
const ll INF=8e7*wiwiho;
const int N=500+10;
int n,m,q;
ll dis[N][N];
void chmin(ll& a,ll b){
	a=min(a,b);
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>q;
	fill(&dis[0][0],&dis[N-1][N-1],INF);
	for(int i=1;i<=n;++i)dis[i][i]=0;
	while(m--){
		int u,v,c;
		cin>>u>>v>>c;
		chmin(dis[u][v],c);
		chmin(dis[v][u],c);
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		if(dis[a][b]==INF)cout<<"-1\n";
		else cout<<dis[a][b]<<'\n';
	}
}
