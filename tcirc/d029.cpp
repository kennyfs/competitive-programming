#include <iostream>
#include <set>
#include <utility>
#include <cstring>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
using namespace std;
int const N=2e5+10,INF=8e7;
int n;
int a[N],b[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)cin>>b[i];
	set<pii> st;
	st.insert({INF,-1});
	ll ans=0;
	for(int i=0;i<n;++i){
		auto big=st.upper_bound({a[i]+b[i],INF});
		ans+=i-big->S-1;
		while(!st.empty()&&st.begin()->F<=a[i])st.erase(st.begin());
		st.insert({a[i],i});
	}
	cout<<ans<<'\n';
}
//set
