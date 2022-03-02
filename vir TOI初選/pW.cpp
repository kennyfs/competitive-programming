#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define wiwiho 5208e7
using namespace std;
int const N=1e3+10;
int n,m,r[N],s[N],d[N],maxs;
int const inf=8e7*wiwiho;
bool check(int c,int e,int t){
	for(int i=1;i<=e;++i){
		if(!d[i])continue;
		//a_n=(s[i]-(n-1)*d[i])
		//a_n<c and a_n-1>=c
		//(s[i]-(n-1)*d[i])<c
		//n-1>(s[i]-c)/d[i]
		//n>(s[i]-c)/d[i]+1
		int tmp=(s[i]-c)/d[i]+2;
		if(tmp>1)t-=tmp-1;
		if(t<0)return 0;
	}
	return 1;
}
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=2;i<=n;++i)cin>>r[i];
	for(int i=1;i<=n;++i)cin>>s[i],maxs=max(maxs,s[i]);
	for(int i=1;i<=n;++i)cin>>d[i];
	int finalans=-inf;
	for(int e=1,T=m,t;e<=n;++e){
		if(e>1)T-=r[e];
		t=T;
		int ans=0;
		//二分搜打掃的最少灰塵量的房間是多少灰塵
		int l=1,r=maxs;//[l,r]
		while(l<r){
			int m=l+r>>1;
			if(check(m,e,t))r=m;
			else l=m+1;
		}
		for(int i=1;i<=e;++i){
			if(!d[i])ans+=
			int tmp=(s[i]-l)/d[i]+1;
			if(tmp<1)continue;
			//a_1 add to a_tmp
			ans+=(2*s[i]-(tmp-1)*d[i])*tmp/2;
		}
		finalans=max(finalans,ans);
	}
	cout<<finalans;
}