#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define m ((l+r)>>1)
#define INF 8e7*15
#define lc cur<<1
#define rc cur<<1|1
using namespace std;
const int N=5e5+10;
int n,q,a[N],seg[4*N];
void build(int cur=1,int l=1,int r=n+1){
	if(l+1==r){seg[cur]=a[l];return;}
	build(lc,l,m);
	build(rc,m,r);
	seg[cur]=max(seg[cur<<1],seg[cur<<1|1]);
}
int query(int ql,int qr,int cur=1,int l=1,int r=n+1){
	if(qr<=l||r<=ql)return -INF;
	if(ql<=l&&r<=qr)return seg[cur];
	return max(query(ql,qr,lc,l,m),query(ql,qr,rc,m,r));
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	build();
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		cout<<query(a,b+1)<<'\n';
	}
}
