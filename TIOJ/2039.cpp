#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
int const N=2e6+10,NUM=1e7,INF=(1ll<<60);
int n,k,a[N];
struct pii{
	int F,S;
	pii():F(0),S(0){}
	pii(int f,int s):F(f),S(s){}
	pii operator+(pii& a){
		return pii(F+a.F,S+a.S);
	}
};
pii dpy[N],dpn[N];//dpy[i] includes i, dpn[i] doesn't
pii& ma(pii& a,pii& b){
	if(a.F==b.F)return a.S>b.S?a:b;
	return a.F>b.F?a:b;
}
int dp(int p){//do panelty and count times when buying it
	for(int i=1;i<=n;++i){
		pii Y=pii(p-a[i],1)+dpn[i-1],N=pii(a[i],0)+dpy[i-1];
		dpy[i]=ma(dpy[i-1],Y);
		dpn[i]=ma(dpn[i-1],N);
	}
	return dpn[n].S;
}
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	int l=-NUM,r=0,t,m;//[l,r)
	dpy[0]=pii(-INF,0);
	dpn[0]=pii(0,0);
	if(dp(0)<=k){cout<<max(0ll,dpn[n].F)<<'\n';return 0;}
	while(l!=r){
		m=(l+r)>>1;
		t=dp(m);
		if(t<k)l=m+1;
		else r=m;
	}
	dp(l);
	cout<<max(0ll,dpn[n].F-l*k)<<'\n';
}
