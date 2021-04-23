#include <iostream>
using namespace std;
const int MAXN=500010;
int n,data[MAXN],seg[4*MAXN],lazy[4*MAXN];
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
	cout<<"push"<<l<<' '<<r<<'\n';
	seg[cur]+=(r-l)*lazy[cur];
	if(l+1!=r)
		lazy[cur<<1]+=lazy[cur],
		lazy[cur<<1|1]+=lazy[cur];
	lazy[cur]=0;
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
	cout<<"add:"<<l<<' '<<r<<'\n';
	if(ql<=l&&r<=qr){lazy[cur]+=val;return;}
	int m=l+r>>1;
	add(cur<<1  ,l,m,ql,qr,val);
	add(cur<<1|1,m,r,ql,qr,val);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>data[i];
	build(1,1,n+1);
	add(1,1,n+1,2,4,0);
	cout<<query(1,1,n+1,1,5)<<'\n';
}
