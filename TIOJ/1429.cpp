#include <iostream>
#include <vector>
#include <queue>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
#define ll long long
#define pql priority_queue<ll>
using namespace std;
const int N=1e5+10;
int n,m,c[N],l[N];
ll ans;
vector<int> G[N],root;
void join(pql& a,pql& b){
	if(a.size()<b.size())swap(a,b);
	while(!b.empty())a.push(b.top()),b.pop();
}
ll dfs(int u,int fa,pql& pq){
	ll sum=c[u];
	pq.push(c[u]);
	pql tmp;
	if(G[u].size()==0)goto done;
	for(int v:G[u]){
		if(v==fa)continue;
		sum+=dfs(v,u,tmp);
		join(pq,tmp);
	}
	done:
	while(sum>m)sum-=pq.top(),pq.pop();
	ans=max(ans,((ll)pq.size())*l[u]);
	return sum;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=1,b;i<=n;++i){
		cin>>b>>c[i]>>l[i];
		if(b==0)root.pb(i);
		else G[b].pb(i);
	}
	pql a;
	dfs(1,1,a);
	cout<<ans;
}
