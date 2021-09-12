#include <iostream>
#include <cstring>
#define INF 80000000
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=30+5;
int n,m;
int a[N][N],dp[N][N][N][N];//dp[i][j][k][l]:=start at [i][j], (k+1)*(l+1) size
int xc[N][N],yc[N][N];//xc[i][j]:=number of 0s in prefix along x-axis ends at [i][j]
int mod(int to,int z){
	return min(z,to-z);
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>a[i][j];
	for(int x=1;x<=n;++x){
		yc[x][0]=0;
		yc[x][1]=(a[x][1]==0);
		for(int y=2;y<=m;++y){
			yc[x][y]=yc[x][y-1]+(a[x][y]==0);
		}
	}
	for(int y=1;y<=m;++y){
		xc[0][y]=0;
		xc[1][y]=(a[1][y]==0);
		for(int x=2;x<=n;++x){
			xc[x][y]=xc[x-1][y]+(a[x][y]==0);
		}
	}
	memset(dp,0,sizeof(dp));
	for(int dx=1;dx<n;++dx){
		for(int dy=1;dy<m;++dy){
			for(int x=1;x+dx<=n;++x){
				for(int y=1;y+dy<=m;++y){
					dp[x][y][dx][dy]=INF;
					//up
					dp[x][y][dx][dy]=min(dp[x][y][dx][dy],mod(dy+1,yc[x][y+dy]-yc[x][y-1])+dp[x+1][y][dx-1][dy]);
					//down
					dp[x][y][dx][dy]=min(dp[x][y][dx][dy],mod(dy+1,yc[x+dx][y+dy]-yc[x+dx][y-1])+dp[x][y][dx-1][dy]);
					//left
					dp[x][y][dx][dy]=min(dp[x][y][dx][dy],mod(dx+1,xc[x+dx][y]-xc[x-1][y])+dp[x][y+1][dx][dy-1]);
					//right
					dp[x][y][dx][dy]=min(dp[x][y][dx][dy],mod(dx+1,xc[x+dx][y+dy]-xc[x-1][y+dy])+dp[x][y][dx][dy-1]);
				}
			}
		}
	}
	cout<<dp[1][1][n-1][m-1]<<'\n';
}
//噁心的四維區間dp
