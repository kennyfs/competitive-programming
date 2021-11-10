#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define wiwiho 5208e7
#define ll long long
using namespace std;
const int N=2.5e3+10;
const ll INF=8e7*wiwiho;
struct E{int u,v,w;};
vector<E> G;
int n,m,pre[N];
ll dis[N];
void print(int cur,int ori){
	if(cur==ori){
		cout<<cur<<' ';
		return;
	}
	print(pre[cur],ori);
	cout<<cur<<' ';
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		G.pb({u,v,w});
	}
	int cur;
	for(int i=0;i<n;++i){
		cur=0;
		for(auto [u,v,w]:G){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pre[v]=u;
				cur=v;
			}
		}
	}
	if(cur){
		cout<<"YES\n";
		int u=cur;
		while(n--)u=pre[u];
		print(pre[u],u);
		cout<<u;
	}else cout<<"NO";
}
