#include <iostream>
#include <vector>
#include <utility>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
using namespace std;
const int N=2e5+10;
int n,m,p,k,color[N];
vector<int> G[N];
int oc(int c){return (c%2)?c+1:c-1;}
void dfs(int u,int c){
	color[u]=c;
	for(int i:G[u])if(!color[i])dfs(i,oc(c));
}
vector<pii> eq;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	int now=1;
	for(int i=0;i<n;++i){
		if(!color[i])dfs(i,now),now+=2;
	}
	cin>>p>>k;
	int a,b;
	vector<int> wrong;
	for(int o=1;o<=p;++o){
		eq.clear();
		bool flag=0;
		for(int j=0;j<k;++j){
			cin>>a>>b;
			if(flag)continue;
			if(color[a]==color[b]){wrong.pb(o);flag=1;continue;}
			for(auto [u,v]:eq)if((color[a]==u&&color[b]==v)||(color[a]==v&&color[b]==u)){wrong.pb(o);flag=1;break;}
			eq.pb({color[a],oc(color[b])});
			eq.pb({color[b],oc(color[a])});
		}
	}
	for(int i:wrong)cout<<i<<'\n';
}
//可能是假解的賽中解
