#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N=3e5+10,M=5e5+10;
int n,m,f[N],sz[N];
struct edge{
	int u,v,w;
}G[M];
int fa(int u){
	if(f[u]==u)return u;
	return f[u]=fa(f[u]);
}
void join(int x,int y){
	if(x==y)return;
	if(sz[x]>sz[y])swap(x,y);
	f[x]=y;
	sz[y]+=sz[x];
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int a,b,c,t=1;t<=m;++t){
		cin>>a>>b>>c;
		G[t]={a,b,c};
	}
	sort(G+1,G+m+1,[&](edge a,edge b){return a.w<b.w;});
	for(int i=1;i<=n;++i)f[i]=i,sz[i]=1;
	ll ans=0;
	for(int i=1;i<=m;++i){
		auto [a,b,w]=G[i];
		int x=fa(a),y=fa(b);
		if(x==y)continue;
		ans+=1ll*sz[x]*sz[y]*w;
		join(x,y);
	}
	cout<<ans;
}
