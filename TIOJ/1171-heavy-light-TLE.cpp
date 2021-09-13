#pragma g++ optimize("Ofast")
#pragma loop_opt(on)
#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
typedef int64_t ll;
#define m ((l+r)>>1)
using namespace std;
int const N=1e5+10,Q=1e6+10;
int n,q,fa[N],dep[N],sz[N],top[N],big[N],ind[N],cnt,in[N];
ll frt[N],dis[N];
ll seg[4*N];int lz[4*N];
void push(int cur,int l,int r){
	if(!lz[cur])return;
	seg[cur]+=lz[cur]*(frt[r-1]-frt[l-1]);
	if(r-l>1){
		lz[cur<<1]+=lz[cur];
		lz[cur<<1|1]+=lz[cur];
	}
	lz[cur]=0;
}
void add(int cur,int l,int r,int ql,int qr){
	if(l>=r||qr<=l||r<=ql)return;
	push(cur,l,r);
	if(ql<=l&&r<=qr){
		++lz[cur];
		return;
	}
	add(cur<<1,l,m,ql,qr);
	add(cur<<1|1,m,r,ql,qr);
	push(cur<<1,l,m);
	push(cur<<1|1,m,r);
	seg[cur]=seg[cur<<1]+seg[cur<<1|1];
}
ll query(int cur,int l,int r,int ql,int qr){
	if(l>=r||qr<=l||r<=ql)return 0;
	if(ql<=l&&r<=qr)return lz[cur]?seg[cur]+lz[cur]*(frt[r-1]-frt[l-1]):seg[cur];
	if(lz[cur])return query(cur<<1,l,m,ql,qr)+query(cur<<1|1,m,r,ql,qr)+lz[cur]*(frt[min(r,qr)-1]-frt[max(l,ql)-1]);
	return query(cur<<1,l,m,ql,qr)+query(cur<<1|1,m,r,ql,qr);
}
struct edge{
	int v,l;//v=a^b
}G[N];
vector<int> E[N];
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x]=f;
	sz[x]=1;
	big[x]=-1;
	for(int i:E[x]){
		int v=G[i].v^x,l=G[i].l;
		if(v==f)continue;
		in[v]=l;
		dis[v]=dis[x]+l;
		dfs(v,x);
		sz[x]+=sz[v];
		if(big[x]==-1||sz[v]>sz[big[x]])big[x]=v;
	}
}
void link(int x,int up){
	top[x]=up;
	frt[cnt]=frt[cnt-1]+in[x];
	ind[x]=cnt++;
	if(big[x]!=-1)link(big[x],up);
	for(int i:E[x]){
		int v=G[i].v^x;
		if(v==fa[x]||v==big[x])continue;
		link(v,v);
	}
}
int sumc;
ll sumd;
void ap(int a){
	sumd+=dis[a];
	++sumc;
	while(top[a]!=1){
		int ta=top[a];
		add(1,1,n+1,ind[ta],ind[a]+1);
		a=fa[ta];
	}
	if(a==1)return;
	add(1,1,n+1,ind[big[1]],ind[a]+1);
}
ll ans(int a){
	ll res=sumc*dis[a]+sumd;
	while(top[a]!=1){
		int ta=top[a];
		res-=2*query(1,1,n+1,ind[ta],ind[a]+1);
		a=fa[ta];
	}
	if(a==1)return res;
	return res-2*query(1,1,n+1,ind[big[1]],ind[a]+1);
}
bool vis[N];
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>q;
	int a,b,l;
	for(int i=1;i<n;++i){
		cin>>a>>b>>l;++a;++b;
		G[i].v=a^b;
		G[i].l=l;
		E[a].pb(i);E[b].pb(i);
	}
	frt[0]=0;
	dep[0]=-1;
	cnt=1;
	dfs(1,0);
	link(1,1);
	int op,x;
	while(q--){
		cin>>op>>x;++x;
		if(op==1){
			if(!vis[x])vis[x]=1,ap(x);
		}else{
			cout<<ans(x)<<'\n';
		}
	}
}
