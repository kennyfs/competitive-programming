#include <iostream>
#include <tuple>
#include <utility>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma comment(linker, "/stack:200000000")


using namespace std;
int n,q;
const int N=200005;
int data[N],sum[4*N],front[4*N],back[4*N];
typedef tuple<int,int,int,int> T;
//best,sum,front,back
//or
//bestl,bestr,frontr,backl
typedef pair<T,T> ptt;
void build(int cur,int l,int r){
	if(l>=r)return;
	if(l+1==r){sum[cur]=front[cur]=back[cur]=data[l];return;}
	int m=l+r>>1;
	build(cur<<1  ,l,m);
	build(cur<<1|1,m,r);
	sum[cur]=sum[cur<<1]+sum[cur<<1|1];
	front[cur]=max(front[cur<<1],sum[cur<<1]+front[cur<<1|1]);
	back[cur]=max(back[cur<<1|1],sum[cur<<1|1]+back[cur<<1]);
}
#define INF 80000000
ptt query(int cur,int l,int r,int ql,int qr){
	if(l>=r||r<=ql||l>=qr)return {make_tuple(-INF,-INF,-INF,-INF),make_tuple(-8787,-8787,-8787,-8787)};
	if(l+1==r)return {make_tuple(data[l],data[l],data[l],data[l]),make_tuple(l,l,l,l)};
	int m=l+r>>1;
	int ans,s,f,b;
	ptt pttl=query(cur<<1,l,m,ql,qr),pttr=query(cur<<1|1,m,r,ql,qr);
	if(get<0>(pttl.first)==-INF)//left is out of range
		return pttr;
	if(get<0>(pttr.first)==-INF)
		return pttl;
	T tl=pttl.first,tr=pttr.first,ttl=pttl.second,ttr=pttr.second;
	
	T ansp=make_tuple(-INF,-INF,-INF,-INF);
	
	ans=max(get<0>(tl),max(get<0>(tr),get<3>(tl)+get<2>(tr)));
	if(ans==get<0>(tr))
		get<0>(ansp)=get<0>(ttr),
		get<1>(ansp)=get<1>(ttr);
	if(ans==get<3>(tl)+get<2>(tr))
		get<0>(ansp)=get<3>(ttl),
		get<1>(ansp)=get<2>(ttr);
	if(ans==get<0>(tl))
		get<0>(ansp)=get<0>(ttl),
		get<1>(ansp)=get<1>(ttl);

	s=get<1>(tl)+get<1>(tr);
	
	f=max(get<2>(tl),get<1>(tl)+get<2>(tr));
	if(f==get<1>(tl)+get<2>(tr))
		get<2>(ansp)=get<2>(ttr);
	if(f==get<2>(tl))
		get<2>(ansp)=get<2>(ttl);
	
	b=max(get<3>(tr),get<3>(tl)+get<1>(tr));
	if(b==get<3>(tr))
		get<3>(ansp)=get<3>(ttr);
	if(b==get<3>(tl)+get<1>(tr))
		get<3>(ansp)=get<3>(ttl);
	return {make_tuple(ans,s,f,b),ansp};
}
int main(){
	Hirasawa_Yui_My_Wife
	int l,r,ans,i=1;
	while(cin>>n>>q){
		cout<<"Case "<<i++<<":\n";
		for(int i=1;i<=n;++i)cin>>data[i];
		build(1,1,n+1);
		while(q--){
			cin>>l>>r;
			ptt tmp=query(1,1,n+1,l,r+1);
			tie(l,r,ignore,ignore)=tmp.second;
			ans=get<0>(tmp.first);
			cout<<l<<' '<<r<<' '<<ans<<'\n';
		}
	}
}
