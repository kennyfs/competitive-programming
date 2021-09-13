#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
#define ll long long
using namespace std;
int const N=1e5+10;
int n,q;
struct edge{int v,l;}G[N];
vector<int> E[N],visited;
int cdep[N],cfa[N],sz[N],big[N];
ll dis[17][N];
bool vis[N],added[N];
void dfs(int x){
	visited.pb(x);
	vis[x]=1;
	sz[x]=1;
	big[x]=0;
	for(int i:E[x]){
		int v=G[i].v^x;
		if(vis[v])continue;
		dfs(v);
		sz[x]+=sz[v];
		big[x]=max(big[x],sz[v]);
	}
}
void upd_dis(int d,int x){
	vis[x]=1;
	for(int i:E[x]){
		int v=G[i].v^x;
		if(vis[v])continue;
		dis[d][v]=dis[d][x]+G[i].l;
		upd_dis(d,v);
	}
}
void build(int x,int dep,int fa){
	visited.clear();
	dfs(x);
	int c=x,S=sz[x];
	for(int i:visited){
		if(max(S-sz[i],big[i])<max(S-sz[c],big[c]))c=i;
		vis[i]=0;
	}
	dis[dep][c]=0;
	upd_dis(dep,c);
	for(int i:visited)vis[i]=0;
	cfa[c]=fa;
	cdep[c]=dep;
	vis[c]=1;
	for(int i:E[c]){
		int v=G[i].v^c;
		if(!vis[v])build(v,dep+1,c);
	}
}
ll ans[N],re[N];
int cnt[N];
void ap(int a){
	for(int p=a,d=cdep[a];p;p=cfa[p],--d){
		ans[p]+=dis[d][a];
		re[p]+=dis[d-1][a];
		++cnt[p];
	}
}
ll query(int a){
	ll res=0;int now=0;
	for(int p=a,d=cdep[a];p;p=cfa[p],--d){
		res+=(ans[p]-re[p])+(cnt[p]-now)*dis[d][a];
		now=cnt[p];
	}
	return res;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>q;
	for(int i=1,a,b,l;i<n;++i){
		cin>>a>>b>>l;++a,++b;
		G[i].v=a^b;G[i].l=l;
		E[a].pb(i);E[b].pb(i);
	}
	build(1,1,0);
	int op,x;
	while(q--){
		cin>>op>>x;++x;
		if(op==1){if(!added[x])added[x]=1,ap(x);}
		else cout<<query(x)<<'\n';
	}
}
