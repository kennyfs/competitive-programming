#include <iostream>
#include <utility>
#include <vector>
#define pii pair<int,int>
using namespace std;
int n,q,u,v,w;
vector<pii> abc[200010],child[200010];
vector<pii> LCA[200010];//{ancestor,len}
/*void dfs_children(int cur,int pre){
	for(pii a:abc[cur]){
		v=a.first,w=a.second;
		if(v==pre)continue;
		child[cur].push_back({v,w});
		dfs_children(v,cur);
	}
}*/
void lca(int cur,int pre){
	int now=pre,nowlen=0;
	unsigned int jump=1;
	while(1){
		LCA[cur].push_back(now);
		if(LCA[now].size()<jump)break;
		now=LCA[now][jump-1];
	}
	for(pii a:abc[cur]){
		if(a.first!=pre)
			lca(a.first,cur);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;++i){
		cin>>u>>v>>w;
		abc[u].push_back({v,w});
		abc[v].push_back({u,w});
	}
	//dfs_children(1,0);
	
	cin>>q;
	for(int i=0;i<q;++i){
		cin>>u>>v;
		
	}
}
