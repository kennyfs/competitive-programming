#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int const N=2e6+10,NUM=1e7+10;
int n,k,a[N],dpy[N],dpn[N],ty[N],tn[N];//dpy[i] includes i, dpn[i] doesn't
int dp(int p){//do panelty and count times when selling it
	dpy[1]=-a[1];
	dpn[1]=ty[1]=tn[1]=0;
	for(int i=2;i<=n;++i){
		if(dpy[i-1]>dpn[i-1]-a[i])dpy[i]=dpy[i-1],ty[i]=ty[i-1];
		else dpy[i]=dpn[i-1]-a[i],ty[i]=tn[i-1];
		if(dpn[i-1]>dpy[i-1]+a[i]-p)dpn[i]=dpn[i-1],tn[i]=tn[i-1];
		else dpn[i]=dpy[i-1]+a[i]-p,tn[i]=tn[i-1]+1;
	}
	int ma=-NUM,t;
	for(int i=1;i<=n;++i)if(dpn[i]>ma||(dpn[i]==ma&&tn[i]==k))ma=dpn[i],t=tn[i];
	cout<<t<<'\n';
	return t;
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	int l=-NUM,r=NUM,t,m;//[l,r)
	if(dp(0)<=k){cout<<*max_element(dpn+1,dpn+n+1)<<'\n';return 0;}
	while(l+1<r){
		m=(l+r)>>1;
		cout<<m<<'\n';
		t=dp(m);
		//if(t==k)break;
		if(t<k)r=m;
		else l=m+1;
	}
	cout<<max(*max_element(dpn+1,dpn+n+1)+m*k,0ll)<<'\n';
}
