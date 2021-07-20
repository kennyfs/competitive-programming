#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1000,INF=80000000;
int n,t,data[N+10],seg[4*N+10];
void build(int cur,int l,int r){
	if(l>=r)return;
	if(l+1==r){seg[cur]=data[l];return;}
	int m=(l+r)>>1;
	build(cur<<1  ,l,m);
	build(cur<<1|1,m,r);
	seg[cur]=max(seg[cur<<1],seg[cur<<1|1]);
}/*
void modify(int cur,int l,int r,int q,int v){//[l,r)
	if(l>=r)return;
	int m=(l+r)>>1;
	if(l==q&&l+1==r)seg[cur]=max(seg[cur],v);
	if(q<m)
		modify(cur<<1  ,l,m,q,v);
	else
		modify(cur<<1|1,m,r,q,v);
	seg[cur]=max(seg[cur<<1],seg[cur<<1|1]);
}*/
int query(int cur,int l,int r,int ql,int qr){
	if(l>=r)return -INF;
	if(r<=ql||qr<=l)return -INF;
	if(ql<=l&&r<=qr)return seg[cur];
	int m=(l+r)>>1;
	return max(query(cur<<1,l,m,ql,qr),query(cur<<1|1,m,r,ql,qr));
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>t;
	for(int i=1;i<=n;++i)cin>>data[i];
	build(1,1,n+1);
	int q;cin>>q;
	int op,a,b;
	while(q--){
		cin>>op;
		if(op==2){
			cin>>a>>b;
			cout<<query(1,1,n+1,max(1,b-a),min(n,b+a)+1)<<'\n';
		}else{
			break;
		}
	}
	return 0;
}
