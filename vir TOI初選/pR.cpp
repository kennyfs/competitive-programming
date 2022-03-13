#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define wiwiho 25
#define pb push_back
int const N=1e5+10,inf=8e7*wiwiho;
using namespace std;
struct p{
	int v,w;
};
struct fs{
	int f,s;
	fs():f(0),s(0){}
	void operator()(int x){
		if(x==f)return;
		if(x>f)swap(f,x);
		if(x>s)swap(s,x);
	}
}ans;
vector<p> G[N];
int n,total_lg,total_seclg,lg[N],seclg[N];
bool vis[N];
fs DP(int u){
	vis[u]=1;
	fs dpu;
	for(auto [v,w]:G[u]){
		if(vis[v])continue;
		fs dpv=DP(v);
		ans(dpu.f+dpv.f+w);
		ans(dpu.f+dpv.s+w);
		ans(dpu.s+dpv.f+w);
		
		dpu(dpv.f+w);
		dpu(dpv.s+w);
	}
	return dpu;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=0,u,v,w;i<n-1;++i){
		cin>>u>>v>>w;
		G[u].pb({v,w});
		G[v].pb({u,w});
	}
	DP(0);
	cout<<ans.s<<'\n';
}
