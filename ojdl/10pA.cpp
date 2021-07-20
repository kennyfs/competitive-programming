#include <iostream>
#include <vector>
using namespace std;
const int INF=80000000;
int n,m;
int u,v;
int dist[510][510];
int main(){
	cin>>n>>m;
	for(int i=0;i<510;++i)
		for(int j=0;j<510;++j)
			dist[i][j]=(i==j)?0:INF;
	for(int i=0;i<m;++i){
		cin>>u>>v;
		dist[u][v]=dist[v][u]=1;
	}
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	/*for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			cout<<dist[i][j]<<' ';
		cout<<'\n';
	}*/
	int best=-INF,tmp,save;
	int bestcnt=0;
	for(u=0;u<n;++u){
		for(v=0;v<n;++v){
			if(u>=v)continue;
			save=0;
			//cout<<u<<" and "<<v<<'\n';
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					if(i>=j)continue;
					tmp=dist[i][j]-min(dist[i][u]+dist[v][j],dist[i][v]+dist[u][j])-1;
					if(tmp>0)save+=tmp;
					//cout<<i<<' '<<j<<','<<tmp<<'\n';
				}
			}
			if(save>best){
				//cout<<"found "<<u<<" and "<<v<<'\n';
				best=save;
				bestcnt=1;
			}else if(save==best){
				++bestcnt;
			}
		}
	}
	cout<<bestcnt<<' '<<best<<'\n';
}
