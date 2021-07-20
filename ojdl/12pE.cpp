#include <iostream>
#include <set>
#include <vector>
#define pb push_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=3060;//ti
int n,m,q;
vector<int> con[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>q;
	int u,v;
	while(m--){
		cin>>u>>v;
		con[u].pb(v);
		con[v].pb(u);
	}
	set<int> ans;	
	int l,r;
	while(q--){
		ans.clear();
		cin>>l>>r;
		for(u=l;u<=r;++u){
			for(int v:con[u]){
				ans.insert(v);
			}
		}
		for(u=l;u<=r;++u)ans.erase(u);
		cout<<ans.size()<<'\n';
	}
}
