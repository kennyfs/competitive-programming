#include <iostream>
#include <vector>
#define pb emplace_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1000+120;
int n,k,dots[N],sz[N];
vector<int> G[N];
int dp[N][N<<1][2],tmp[N<<1][2];
//dp[i][j][k]: from i walk j steps, k=0:go back to i, k=1:don't go back to i
//all dp[i][j][k] should consider itself's dots(dots[i])
void dfs(int u,int fa){
	Hirasawa_Yui_My_Wife
	dp[u][0][0]=dp[u][0][1]=dots[u];
	sz[u]=1;
	for(int v:G[u]){if(v==fa)continue;
		//考慮把v加入目前走過的子節點
		dfs(v,u);
		for(int i=0;i<=min(k,sz[u]*2+sz[v]*2);++i){//init 這個函數內的原則是寧可多做不能少做
			tmp[i][0]=dp[u][i][0];
			tmp[i][1]=dp[u][i][1];//只需要滾動一部份
		}
		for(int i=0;i<=sz[u]*2;++i){
			for(int j=0;j<=sz[v]*2;++j){
				if(i+j+2>k)break;//2:u->v and u->v
				tmp[i+j+2][0]=max(tmp[i+j+2][0],dp[v][j][0]+dp[u][i][0]);//end at u
				tmp[i+j+2][1]=max(tmp[i+j+2][1],dp[v][j][0]+dp[u][i][1]);//end in other subtree than v
			}
			for(int j=0;j<=sz[v]*2;++j){
				if(i+j+1>k)break;//1:u->v
				tmp[i+j+1][1]=max(tmp[i+j+1][1],dp[u][i][0]+dp[v][j][1]);//end in subtree of v
			}
		}
		for(int i=0;i<=min(k,sz[u]*2+sz[v]*2);++i){
			dp[u][i][0]=tmp[i][0];
			dp[u][i][1]=tmp[i][1];
		}
		sz[u]+=sz[v];
	}
}
int main(){
	cin>>n>>k;if(k>2*n-2)k=2*n-2;
	for(int i=1;i<=n;++i)cin>>dots[i];
	int u,v;
	for(int i=1;i<=n-1;++i){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0);
	int ans=0;
	for(int i=0;i<=k;++i)ans=max(ans,max(dp[1][i][0],dp[1][i][1]));
	cout<<ans<<'\n';
}
