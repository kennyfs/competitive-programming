#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int MAXN=500010;
int n,data[MAXN],seg[4*MAXN],lazy[4*MAXN],m;
void build(int cur,int l,int r){//[l,r)
	if(l>=r)return;
	if(l+1==r){
		seg[cur]=data[l];
		return;
	}
	int m=l+r>>1;
	build(cur<<1,l,m);build(cur<<1|1,m,r);
	seg[cur]=seg[cur<<1]+seg[cur<<1|1];
}
void push(int cur,int l,int r){
	if(l>=r)return;
	seg[cur]+=(r-l)*lazy[cur];
	if(l+1!=r)
		lazy[cur<<1]+=lazy[cur],
		lazy[cur<<1|1]+=lazy[cur];
	lazy[cur]=0;
}
void pull(int cur,int l,int r){
	if(l>=r)return;
	int m=l+r>>1;
	seg[cur]=	seg[cur<<1]+(m-l)*lazy[cur<<1]+
				seg[cur<<1|1]+(r-m)*lazy[cur<<1|1];
}
int query(int cur,int l,int r,int ql,int qr){
	if(l>=r||ql>=r||qr<=l)return 0;
	push(cur,l,r);
	if(ql<=l&&r<=qr)return seg[cur];
	int m=l+r>>1;
	return query(cur<<1,l,m,ql,qr)+query(cur<<1|1,m,r,ql,qr);
}
void add(int cur,int l,int r,int ql,int qr,int val){
	if(l>=r||ql>=r||qr<=l)return;
	if(ql<=l&&r<=qr){lazy[cur]+=val;return;}
	int m=l+r>>1;
	add(cur<<1  ,l,m,ql,qr,val);
	add(cur<<1|1,m,r,ql,qr,val);
	pull(cur,l,r);
}
main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	int N=n+1;
	for(int i=1;i<=n;++i)cin>>data[i];
	build(1,1,N);
	cin>>m;
	int a,b,c;
	while(m--){
		cin>>a>>b>>c;
		if(a==1){
			cin>>a;
			if(b>=c)swap(b,c);
			add(1,1,N,b,c+1,a);
		}else{
			if(b>=c)swap(b,c);
			cout<<query(1,1,N,b,c+1)<<'\n';
		}
	}
}
