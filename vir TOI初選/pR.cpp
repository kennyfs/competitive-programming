#include <iostream>
#include <vector>
#define pb push_back
int const N=1e5+10;
using namespace std;
struct p{
	int v,w;
};
vector<p> G[N];
int n,total_lg,total_seclg,lg[N],seclg[N];
bool vis[N];
void DP(int u){
	cout<<"in:"<<u<<'\n';
	vis[u]=1;
	int tmplg=0,tmpseclg=0;
	for(auto [v,w]:G[u]){
		if(vis[v])continue;
		DP(v);
		tmplg=max(tmplg,lg[u]+lg[v]+w);
		int toup[3]={lg[u]+seclg[v]+w,seclg[u]+lg[v]+w,lg[u]};
		for(int i:toup){cout<<i<<',';if(i<tmplg)tmpseclg=max(tmpseclg,i);}
		cout<<'\n';
		cout<<tmplg<<' '<<tmpseclg<<'\n';
		lg[u]=max(lg[u],lg[v]+w);
		if(lg[u]!=lg[v]+w){
			seclg[u]=max(seclg[u],lg[v]+w);
		}
		seclg[u]=max(seclg[u],seclg[v]+w);
	}
	total_lg=max(total_lg,tmplg);
	total_seclg=max(total_seclg,tmpseclg);
	cout<<"out:"<<u<<'\n';
}
int main(){
	cin>>n;
	for(int i=0,u,v,w;i<n-1;++i){
		cin>>u>>v>>w;
		G[u].pb({v,w});
		G[v].pb({u,w});
	}
	DP(0);
	cout<<total_lg<<' '<<total_seclg<<'\n';
}
