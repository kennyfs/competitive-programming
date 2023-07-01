#include <bits/stdc++.h>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
const int N=2e5+156;
int n,m,p;
pii coupon[N];
string s;
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	multiset<int> st;
	int ans=0;
	for(int i=1;i<=n;++i){cin>>p;st.insert(p);ans+=p;}
	for(int i=1;i<=m;++i)cin>>coupon[i].f;
	for(int i=1;i<=m;++i)cin>>coupon[i].s;
	sort(coupon+1,coupon+m+1,[](pii a,pii b){return a.s>b.s;});
	for(int i=1;i<=m;++i){
		auto find=st.lower_bound(coupon[i].f);
		if(find!=st.end()){
			st.erase(find);
			ans-=coupon[i].s;
		}
	}
	cout<<ans<<'\n';
}
