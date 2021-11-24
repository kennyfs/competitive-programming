#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 8e7
using namespace std;
const int N=23;
int n,q,a[N][N],dis[N][N][N][N][2];
int nxt[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)cin>>a[i][j];
	fill(&dis[0][0][0][0][0],&dis[N-1][N-1][N-1][N-1][1]+1,INF);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
		dis[i][j][i][j][0]=dis[i][j][i][j][1]=0;
		for(int k=0;k<4;++k){
			int tx=i+nxt[k][0],ty=j+nxt[k][1];
			if(tx>n||tx<1||ty>n||ty<1)continue;
			dis[i][j][tx][ty][0]=a[i][j];
			dis[i][j][tx][ty][1]=0;
		}
	}
	for(int kx=1;kx<=n;++kx){
		for(int ky=1;ky<=n;++ky){
			for(int sx=1;sx<=n;++sx){
				for(int sy=1;sy<=n;++sy){
					for(int ex=1;ex<=n;++ex){
						for(int ey=1;ey<=n;++ey){
							dis[sx][sy][ex][ey][1]=min(dis[sx][sy][ex][ey][1],min(dis[sx][sy][kx][ky][0]+dis[kx][ky][ex][ey][1],dis[sx][sy][kx][ky][1]+dis[kx][ky][ex][ey][0]));
							dis[sx][sy][ex][ey][0]=min(dis[sx][sy][ex][ey][0],dis[sx][sy][kx][ky][0]+dis[kx][ky][ex][ey][0]);
						}
					}
				}
			}
		}
	}
	cin>>q;
	while(q--){
		int sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		cout<<min(dis[sx][sy][ex][ey][0],dis[sx][sy][ex][ey][1]+a[ex][ey])<<'\n';
	}
}

