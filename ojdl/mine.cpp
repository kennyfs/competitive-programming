#include <iostream>
#include <algorithm>
#define INF 8000000
#define GOAL 10
using namespace std;
int const N=1e3+10;
int s[N][N],dp[N][N],all[N*N];
int n,m,k,u;
int main(){
	cin>>n>>m>>k>>u;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>s[i][j];
		}
	}
	int t,x,y;
	for(int i=1;i<=k;++i){
		cin>>x>>y;
		s[x][y]=-INF;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			all[(i-1)*m+j-1]=s[i][j];
		}
	}
	while(u--){
		cin>>t>>x>>y;
		if(t<=x+y-1)s[x][y]=-INF;
	}
	//dp
	int dpminstep=INF,greedyminstep=INF;
	for(int i=1;i<=n;++i){dp[i][1]=dp[i-1][1]+s[i][1];if(s[i][1]<0)dp[i][1]=-INF;}
	for(int i=1;i<=m;++i){dp[1][i]=dp[1][i-1]+s[1][i];if(s[1][i]<0)dp[1][i]=-INF;}
	for(int i=2;i<=n;++i){
		for(int j=2;j<=m;++j){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+s[i][j];
			if(s[i][j]<0)dp[i][j]=-INF;
			if((dp[i][j]<<1)>=GOAL)dpminstep=min(dpminstep,i+j-1);
		}
	}
	sort(all,all+n*m,[&](int a,int b){return a>b;});
	int now=0;
	for(int i=0;i<n*m;++i){
		now+=all[i];
		if(now>=GOAL){greedyminstep=i+1;break;}
	}
	if(dpminstep==INF&&greedyminstep==INF)cout<<"NO Giita QQ";
	else cout<<min(dpminstep,greedyminstep);
}
