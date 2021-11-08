#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
using namespace std;
const int N=2e4+10,P=1e4+10;
int n,m,p,k;
vector<int> G[N];
int color[N],lead[N],f[N],sz[N];//lead[i]=lead of color i
int oc(int c){return (c%2)?c+1:c-1;}
vector<int> ch;
int fa(int u){//zip = if 路徑壓縮
	if(f[u]==u)return u;
	ch.pb(u);
	return f[u]=fa(f[u]);
}
void dfs(int u,int c){
	color[u]=c;
	for(int i:G[u])if(!color[i])dfs(i,oc(c));
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	int u,v;
	while(m--){
		cin>>u>>v;
		++u;++v;
		G[u].pb(v);
		G[v].pb(u);
	}
	int now=1;
	for(int i=1;i<=n;++i){
		if(!color[i])dfs(i,now),now+=2;
	}
	cin>>p>>k;
	for(int i=1;i<=now;++i)f[i]=i;
	vector<int> wrong;
	for(int o=1;o<=p;++o){
		now=0;
		bool flag=0;
		ch.clear();
		for(int i=0;i<k;++i){
			cin>>u>>v;
			++u;++v;
			if(flag)continue;
			int cu=color[u],cv=color[v];
			int x=fa(cu),y=fa(cv);
			if(x==y){wrong.pb(o);flag=1;continue;}
			f[x]=fa(oc(cv));
			f[y]=fa(oc(cu));
			ch.pb(x);
			ch.pb(y);
		}
		for(int i:ch)f[i]=i;
	}
	for(int i:wrong)cout<<i<<'\n';
}
