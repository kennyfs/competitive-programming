#include <iostream>
#include <vector>
#define ll long long
#define pb push_back
using namespace std;
int const N=210,mod=1e9+7;
int n;
int inv[N],dp[N][N],lca[N][N],dep[N];
vector<int> g[N],s[N];
void dfs(int cur,int fa){//cur=current, fa=father(don't go to fa)
	s[cur]={cur};dep[cur]=(fa>=0)?dep[fa]+1:1;
	for(int child:g[cur]){
		if(child==fa)continue;
		dfs(child,cur);
		for(int x:s[child]){
			for(int y:s[cur]){
				lca[x][y]=lca[y][x]=cur;
			}
		}
		for(int x:s[child])s[cur].pb(x);
	}
}
void add(int& a,int b){
	a+=b;
	if(a>=mod)a-=mod;
}
int main(){
	cin>>n;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=(ll)inv[mod%i]*(mod-mod/i)%mod;//https://yuihuang.com/modular-multiplicative-inverse/
	//dp[i][j] means the possibility to reach the node which is i steps away before to reach the node which is j steps away.
	for(int i=0;i<=n;++i)dp[i][0]=0,dp[0][i]=1;//don't care dp[0][0], I won't use it
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dp[i][j]=(ll)(dp[i-1][j]+dp[i][j-1])*inv[2]%mod;
	int u,v;
	for(int i=1;i<n;++i){
		cin>>u>>v;
		--u;--v;
		g[u].pb(v);g[v].pb(u);
	}
	int ans=0;
	for(int rt=0;rt<n;++rt){
		dfs(rt,-1);//find lca of every two nodes(rt as the root) and depth of every node
		for(int x=0;x<n;++x){
			for(int y=x+1;y<n;++y){//x<y, so add the possibility to reach y before to reach x
				add(ans,dp[dep[y]-dep[lca[x][y]]][dep[x]-dep[lca[x][y]]]);
			}
		}
	}
	cout<<((ll)ans*inv[n]%mod)<<'\n';
}

/*
 * Reference:
 * https://codeforces.com/contest/1540/submission/121177611
 * https://www.cnblogs.com/liankewei/p/14939849.html
 * https://yuihuang.com/modular-multiplicative-inverse/
*/
