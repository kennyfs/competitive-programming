#include <iostream>
#include <vector>
#define ll long long
#define pb emplace_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const T=1000,N=200+10;
int n,m,s;
ll t;
ll dp[T][N];
vector<int> G[N];
int c[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>s>>t;
	for(int i=1;i<=n;++i)cin>>c[i];
	int u,v;
	while(m--){
		cin>>u>>v;
		G[u].pb(v);
	}
	bool flag=1;
	for(int i=1;i<=n;++i)if(G[i].size()>1){flag=0;break;}
	if(flag){
		ll p[N];
		p[0]=0;
		int cur=G[s][0],i=0;
		while(true){
			p[i+1]=p[i]+1ll*c[cur];
			++i;
			if(cur==s)break;
			if(i>n)goto jizz;
			cur=G[cur][0];
		}
		cout<<(t/i)*p[i]+p[t%i]<<'\n';
		return 0;
	}
	jizz:
	if(t>1000)return 0;
	fill(&dp[0][0],&dp[0][0]+T*N,-1ll<<62);
	dp[0][s]=0;
	for(int i=0;i<=t-1;++i){
		for(int u=1;u<=n;++u){
			if(dp[i][u]==-1ll<<62)continue;
			for(int v:G[u]){
				dp[i+1][v]=max(dp[i+1][v],dp[i][u]+1ll*c[v]);
			}
		}
	}
	ll ans=-1ll<<62;
	for(int u=1;u<=n;++u){
		ans=max(ans,dp[t][u]);
	}
	cout<<ans<<'\n';
}
