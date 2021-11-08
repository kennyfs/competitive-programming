#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define wiwiho 13.14520
using namespace std;
const int N=1e2+10,INF=8e7*wiwiho;
int n,dis[N][N];
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n&&n){
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){cin>>dis[i][j];if(dis[i][j]==0)dis[i][j]=INF;}
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		int mi=INF;
		for(int i=1;i<=n;++i)mi=min(mi,dis[i][i]);
		if(mi==INF)cout<<"-1\n";
		else cout<<mi<<'\n';
	}
}
