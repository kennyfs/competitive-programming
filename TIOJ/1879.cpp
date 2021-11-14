#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define pb emplace_back
using namespace std;
const int N=1e4+10;
int n,m,cnt,bcctot,vis[N],low[N],E[8*N];
vi G[N],bcc[N];
bool instack[N];
stack<int> stk;
void dfs(int u,int be=-1){//be: edge from last vertex
	++cnt;
	vis[u]=low[u]=cnt;
	instack[u]=1;
	stk.push(u);
	for(int e:G[u]){
		int v=E[e];
		if(!vis[v]){
			dfs(v,e^1);
			low[u]=min(low[u],low[v]);
			if(low[v]>vis[u]){//u-v is bridge
				++bcctot;
				int cur;
				do{
					cur=stk.top();stk.pop();
					bcc[bcctot].pb(cur);
					instack[cur]=0;
				}while(cur!=v);
			}
		}
		else if(instack[v]&&e!=be)low[u]=min(low[u],low[v]);
	}
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	int ind=0;
	while(m--){
		int u,v;
		cin>>u>>v;++u,++v;
		G[u].pb(ind);
		E[ind++]=v;
		G[v].pb(ind);
		E[ind++]=u;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			dfs(i);
			++bcctot;
			while(!stk.empty()){
				bcc[bcctot].pb(stk.top());
				stk.pop();
			}
		}
	}
	for(int i=1;i<=bcctot;++i){
		sort(bcc[i].begin(),bcc[i].end());
	}
	sort(bcc+1,bcc+bcctot+1,[&](vi a,vi b){return a[0]<b[0];});
	for(int i=1;i<=bcctot;++i){
		cout<<i<<':';
		for(int j:bcc[i])cout<<' '<<j-1;
		cout<<'\n';
	}
}
