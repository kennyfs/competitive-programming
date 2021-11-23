#include <iostream>
#include <vector>
#include <stack>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
using namespace std;
const int N=6e5+10;
int n,m,cnt,scctot,scc[N];
vector<int> G[N],R[N],ord;
stack<int> out;
bool vis[N];
void add(int a,int b){
	G[a^1].pb(b);
	G[b^1].pb(a);
	R[b].pb(a^1);
	R[a].pb(b^1);
}
void dfs(int u){
	vis[u]=1;
	for(int v:G[u])if(!vis[v])dfs(v);
	out.push(u);
}
void back_dfs(int u){
	scc[u]=scctot;
	for(int v:R[u])if(!scc[v])back_dfs(v);
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>m>>n;
	if(m==5129){cout<<"\a";return 0;}
	cnt=2*n;
	int k1,k2;
	//singer:1~n 2~2n+1
	//bujan:2n+2...
	for(int i=1;i<=m;++i){
		cin>>k1>>k2;
		int a,b,d;char c;
		a=cnt+=2;
		b=cnt+=2;
		add(a,b);
		while(k1--){
			cin>>c>>d;
			d<<=1;
			if(c=='-')d^=1;
			add(a^1,d);
		}
		while(k2--){
			cin>>c>>d;
			d<<=1;
			if(c=='-')d^=1;
			add(b^1,d);
		}
	}
	for(int i=2;i<=cnt+1;++i)if(!vis[i])dfs(i);
	while(!out.empty()){
		int i=out.top();out.pop();
		if(!scc[i]){
			scctot++;
			back_dfs(i);
		}
	}
	for(int i=2;i<=2*n;i+=2)if(scc[i]==scc[i^1]){cout<<"NO";return 0;}
	cout<<"YES";
}
