#include <iostream>
#include <vector>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N=2e5+10,M=5e5+10;
int n,m,f[N];
struct E{int u,v,w;}G[M];
int fa(int u){
	if(f[u]==u)return u;
	return f[u]=fa(f[u]);
}
void join(int a,int b){
	int x=fa(a),y=fa(b);
	if(x==y)return;
	f[x]=y;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int a,b,c,i=0;i<m;++i){
		cin>>a>>b>>c;
		G[i]={a,b,c};
	}
	sort(G,G+m,[&](E a,E b){return a.w>b.w;});
	ll ans=0;
	for(int i=1;i<=n;++i)f[i]=i;
	int e=0;
	for(int i=0;i<m;++i){
		auto [u,v,w]=G[i];
		if(fa(u)==fa(v))continue;
		ans+=w;
		join(u,v);
		++e;
	}
	if(e!=n-1)cout<<"Hirasawa Yui So Cute";
	else cout<<ans;
}
