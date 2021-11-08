#include <iostream>
#include <vector>
#include <cstring>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mid ((l+r)>>1)
using namespace std;
const int N=2e4+10,P=1e4+10;
int n,m,p,k,color[N];
int oc(int c){return (c%2)?c+1:c-1;}
struct edge{int a,b;};
vector<edge> E[N];
vector<int> G[N],wrong;
bool ok(int u,int c){
	color[u]=c;
	for(int i:G[u]){
		if(color[i]==color[u])return 0;
		if(!color[i]&&!ok(i,oc(c)))return 0;
	}
	return 1;
}
bool check(int p){//return if wrong
	memset(color,0,sizeof(color));
	for(int i=0;i<n;++i)G[i].clear();
	for(int i=0;i<=p;++i){
		for(auto [a,b]:E[i]){
			G[a].pb(b);
			G[b].pb(a);
		}
	}
	for(int i=0;i<n;++i)if(!color[i]&&!ok(i,1))return 1;
	return 0;
}
void BS(){
	int l=1,r=p;
	if(!check(r))return;
	while(l!=r){
		if(check(mid))r=mid;
		else l=mid+1;
	}
	E[l].clear();
	wrong.pb(l);
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	int u,v;
	while(m--){
		cin>>u>>v;
		E[0].pb({v,u});
	}
	cin>>p>>k;
	for(int i=1;i<=p;++i){
		for(int j=0;j<k;++j){
			cin>>u>>v;
			E[i].pb({u,v});
		}
	}
	for(int i=0;i<3;++i)BS();
	for(int i:wrong)cout<<i<<'\n';
}
