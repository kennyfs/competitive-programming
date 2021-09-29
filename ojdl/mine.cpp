#include <iostream>
#include <algorithm>
#include <queue>
#define INF 8000000
#define GOAL 250000
#define int long long
using namespace std;
int const N=1e3+10;
int s[N][N],dp[N][N];
struct g{int t,v;}all[N*N];
int n,m,k,u;
bool operator<(g a,g b){return a.v>b.v;}
priority_queue<g> pq;
signed main(){
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
			all[(i-1)*m+j-1]={INF,s[i][j]};
		}
	}
	while(u--){
		cin>>t>>x>>y;
		if(t<=x+y-1)s[x][y]=-INF,all[(x-1)*m+y-1].t=t-1;
	}
	//dp
	int dpminstep=INF,greedyminstep=INF;
	for(int i=1;i<=n;++i){dp[i][1]=dp[i-1][1]+s[i][1];if(s[i][1]<0)dp[i][1]=-INF;if((dp[i][1]<<1)>=GOAL)dpminstep=min(dpminstep,i);}
	for(int i=1;i<=m;++i){dp[1][i]=dp[1][i-1]+s[1][i];if(s[1][i]<0)dp[1][i]=-INF;if((dp[1][i]<<1)>=GOAL)dpminstep=min(dpminstep,i);}
	for(int i=2;i<=n;++i){
		for(int j=2;j<=m;++j){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+s[i][j];
			if(s[i][j]<0)dp[i][j]=-INF;
			if((dp[i][j]<<1)>=GOAL)dpminstep=min(dpminstep,i+j-1);
		}
	}
	sort(all,all+n*m,[&](g a,g b){return a.t<b.t;});
	int l=1,r=n*m+1,st=0;//[l,r)
	while(all[st].t==0)st++;
	while(l<r){
		while(!pq.empty())pq.pop();
		ll now=0;int M=(l+r)>>1;
		for(int i=st;i<n*m;++i){
			if(all[i].t<=pq.size()||pq.size()==M){if(all[i].v>pq.top().v)now+=all[i].v-pq.top().v,pq.pop(),pq.push(all[i]);}
			else{pq.push(all[i]);now+=all[i].v;}
		}
		if(GOAL<=now)r=M;
		else l=M+1;
	}
	if(dpminstep==INF&&l==n*m+1)cout<<"NO Giita QQ";
	else cout<<min(dpminstep,l);
}
