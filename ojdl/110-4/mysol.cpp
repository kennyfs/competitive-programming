#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#define pb push_back
using namespace std;
int const N=1e5+10;
int n,k;
struct e{int v,w;};
vector<e> G[N];
int a[N];
long long ans,cnt;
bool vis[N];
int dfs(int u,int fa){
	this_thread::sleep_for(chrono::nanoseconds(1000000));
	if(++cnt%1000==0)cout<<cnt<<'\n';
	vis[u]=1;
	int sum=a[u]-k;
	for(auto [v,w]:G[u]){
		if(v==fa)continue;
		if(vis[v]){cout<<"error "<<v<<endl;}
		int tmp=dfs(v,u);
		ans+=1ll*abs(tmp)*w;
		sum+=tmp;
	}
	return sum;
}
int main(){
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
		G[i].clear();
	}
	if(sum!=n*k){cout<<"Hirasawa Yui is the cutest";return 0;}
	for(int i=1,u,v,w;i<n;++i){
		cin>>u>>v>>w;
		G[u].pb({v,w});
		G[v].pb({u,w});
	}
	ans=0;
	dfs(1,0);
	cout<<ans;
}
