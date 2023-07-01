#include <bits/stdc++.h>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int N=156;
int n,m,p0;
string c[N],d[N];
map<string, int> mp;
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int i=1;i<=m;++i)cin>>d[i];
	cin>>p0;
	for(int i=1;i<=m;++i){
		int p;cin>>p;
		mp[d[i]]=p;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(mp.count(c[i])!=0){
			ans+=mp[c[i]];
		}else{
			ans+=p0;
		}
	}
	cout<<ans<<'\n';
}
