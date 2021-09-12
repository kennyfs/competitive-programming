#include <iostream>
#include <cstring>
#include <unordered_map>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
int const N=2e5+10;
int n,m;
string a[N];
unordered_map<string,int> mp;
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>m>>n){
		for(int i=0;i<n;++i)cin>>a[i];
		mp.clear();
		int cnt=0;
		for(int i=0;i<m;++i){
			if(!mp[a[i]])++cnt;
			++mp[a[i]];
		}
		int ans=(cnt==m);
		for(int i=m;i<n;++i){//remove i-m,push i
			--mp[a[i-m]];
			if(mp[a[i-m]]==0)--cnt;
			if(mp[a[i]]==0)++cnt;
			++mp[a[i]];
			ans+=(cnt==m);
		}
		cout<<ans<<'\n';
	}
}
//用string存大數，map對應出現次數，單調隊列
