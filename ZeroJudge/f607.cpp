#include <iostream>
#include <set>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
int const N=2e5+10;
int n,l,p[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>l;
	int a,b;
	for(int i=0;i<n;++i)cin>>a>>b,p[b]=a;
	set<int> cut;
	cut.insert(0);
	cut.insert(l);
	ll ans=0;
	for(int i=1;i<=n;++i){
		auto it=cut.lower_bound(p[i]);
		ans+=*it-*prev(it);
		cut.insert(p[i]);
	}
	cout<<ans<<'\n';
}
