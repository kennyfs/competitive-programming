#include <iostream>
#include <algorithm>
#include <queue>
#define INF 8000000
#define GOAL 250000
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e3+10;
int s[N][N],dp[N][N];
struct g{
	int t,v;
	g():t(0),v(0){}
	g(int a,int b):t(a),v(b){}
}all[N*N];
int n,m,k,u;
bool operator<(g a,g b){return a.v<b.v;}
priority_queue<g> pq;
signed main(){
	Hirasawa_Yui_My_Wife
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
		if(t<=x+y-1)s[x][y]=-INF;
		all[(x-1)*m+y-1].t=t-1;
	}
	int dpminstep=INF;
	//dp
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			dp[i][j]=min(1000000,max(dp[i-1][j],dp[i][j-1])+s[i][j]);
			if(s[i][j]<0)dp[i][j]=-INF;
			if((dp[i][j]*3)>=GOAL){dpminstep=min(dpminstep,i+j-1);continue;}
		}
	}
	sort(all,all+n*m,[&](g a,g b){return a.t<b.t;});
	int l=1,r=n*m+1;//[l,r)
	while(l<r){
		while(!pq.empty())pq.pop();
		int now=0,ind=n*m-1;int M=(l+r)>>1;
		for(int i=M;i;--i){
			while(ind>=0&&all[ind].t>=i)pq.push(all[ind--]);
			now+=pq.top().v;pq.pop();
			if(GOAL<=now)break;
		}
		if(GOAL<=now)r=M;
		else l=M+1;
	}
	if(dpminstep==INF&&l==n*m+1)cout<<"NO Giita QQ";
	else cout<<min(dpminstep,l);
}
