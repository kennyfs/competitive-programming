#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,m,sx,sy,ex,ey,k;
bool dp[2][101][101];
#define add(a,b,n) (a+b<n?a+b:a+b-n)
#define sub(a,b,m) (a-b>=0?a-b:a-b+m)
int main(){
	Hirasawa_Yui_My_Wife
	fill(&dp[0][0][0],&dp[1][0][0],false);
	
	cin>>n>>m;
	cin>>sx>>sy>>ex>>ey;
	dp[0][sx][sy]=true;
	cin>>k;
	int a=1,b=0,d,dx,dy;//based on a, update b
	for(int i=0;i<k;++i){
		swap(a,b);
		cin>>d;
		dx=d%n;
		dy=d%m;
		for(int x=0;x<n;++x)
			for(int y=0;y<m;++y)
				dp[b][x][y]=dp[a][add(x,dx,n)][y]|
							dp[a][sub(x,dx,n)][y]|
							dp[a][x][add(y,dy,m)]|
							dp[a][x][sub(y,dy,m)];
	}
	cout<<(dp[b][ex][ey]?"YES\n":"NO\n");
	return 0;
}
