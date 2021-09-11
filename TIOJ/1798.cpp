#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
using namespace std;
int const N=1e6+10;
int n,m,k,q,dep[N],sz[N],up[N],bson[N],fa[N];//sz[i]：i為根的子樹的大小, up 對每個點存樹鍊的最頂端, bson sz最大的兒子
int ind[N],frt[N],cnt;//ind 每個點在frt位置, frt 建的時候是差分->O(N)變前綴（0的個數的前綴）
vector<int> G[N];
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x]=f;
	sz[x]=1;
	bson[x]=-1;
	for(int v:G[x]){
		if(v==f)continue;
		dfs(v,x);
		sz[x]+=sz[v];
		if(bson[x]==-1||sz[v]>sz[bson[x]])bson[x]=v;
	}
}
void link(int x,int top){
	up[x]=top;
	ind[x]=cnt++;
	if(bson[x]!=-1)link(bson[x],top);
	for(int v:G[x]){
		if(v==fa[x]||v==bson[x])continue;
		link(v,v);
	}
}
void addtrain(int a,int b){
	while(up[a]!=up[b]){
		int ta=up[a],tb=up[b];
		if(dep[ta]<dep[tb])swap(a,b),swap(ta,tb);
		//move a to fa[ta]
		++frt[ind[ta]];--frt[ind[a]+1];
		a=fa[ta];
	}
	if(a!=b){
		if(a<b)swap(a,b);
		++frt[ind[b]+1];--frt[ind[a]+1];
	}
}
bool check(int a,int b){
	int ans=0;
	while(up[a]!=up[b]){
		int ta=up[a],tb=up[b];
		if(dep[ta]<dep[tb])swap(a,b),swap(ta,tb);
		ans+=frt[ind[a]]-frt[ind[ta]-1];
		a=fa[ta];
	}
	if(a!=b){
		if(dep[a]<dep[b])swap(a,b);
		ans+=frt[ind[a]]-frt[ind[b]];
	}
	return ans==0;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>k>>q;
	int u,v;
	while(m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	//root at 1
	dep[0]=0;
	dfs(1,0);
	cnt=1;
	link(1,1);
	while(k--){
		cin>>u>>v;
		addtrain(u,v);
	}
	for(int i=1;i<=n;++i)frt[i]+=frt[i-1];
	for(int i=1;i<=n;++i)frt[i]=!frt[i];//frt[i]>0 = 那個地方有被火車覆蓋到，否則沒有
	for(int i=1;i<=n;++i)frt[i]+=frt[i-1];
	while(q--){
		cin>>u>>v;
		cout<<check(u,v)<<'\n';
	}
}
//https://omeletwithoutegg.github.io/2020/02/23/TIOJ-1798/
