#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2e5+10,K=5e4+10;
int n,k,h[N],w[K],space[N];
bool check(int hi){
	int now=0,t=1;
	for(int i=1;i<=n;++i){
		if(h[i]>=hi)++now;
		else if(now)space[t++]=now,now=0;
	}
	if(now)space[t++]=now;
	now=1;
	for(int i=1;i<=k;++i){
		while(now<=t&&w[i]>space[now])++now;
		if(now>t)return 0;
		if(w[i]==space[now])++now;
		else space[now]-=w[i];
	}
	return 1;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>k;
	int mx;
	cin>>h[1];
	mx=h[1];
	for(int i=2;i<=n;++i)cin>>h[i],mx=(mx>h[i])?mx:h[i];
	for(int i=1;i<=k;++i)cin>>w[i];
	int l=1,r=mx+1;//[l,r)
	while(l+1<r){
		int m=l+r>>1;
		if(check(m))l=m;
		else r=m;
	}
	cout<<l;
}
