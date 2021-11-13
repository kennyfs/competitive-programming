#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
const int N=1e3+10;
int n,m;
unordered_map<int,set<int>> G;
int main(){
	cin>>n>>m;
	if(m>((n*(n+1))>>1)){cout<<"Yes";return 0;}
	while(m--){
		int u,v;
		cin>>u>>v;
		if(u>v)swap(u,v);
		if((G.count(u)&&G[u].count(v))||u==v){cout<<"Yes";return 0;}
		G[u].insert(v);
	}
	cout<<"yes";
}
