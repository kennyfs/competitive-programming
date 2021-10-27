#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#define pb emplace_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5+10;
int n,m;
bool vis[N];
vector<int> G[N];
int ind[N];
int last[N];
stack<int> ans;
void print(int cur){
	while(cur){
		ans.push(ind[cur]);
		cur=last[cur];
	}
	cout<<ans.size()+1<<"\n1 ";
	while(!ans.empty())cout<<ans.top()<<' ',ans.pop();
	cout<<'\n';
}
int main(){
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		G[u].pb(v);G[v].pb(u);
	}
	vis[0]=1;
	ind[0]=1;
	int head=0,tail=1;
	while(head<tail){
		for(int nxt:G[ind[head]]){
			if(vis[nxt])continue;
			vis[nxt]=1;
			ind[tail]=nxt;
			last[tail]=head;
			if(nxt==n){print(tail);return 0;}
			++tail;
		}
		++head;
	}
	cout<<"IMPOSSIBLE\n";
}
