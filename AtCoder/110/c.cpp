#include <iostream>
using namespace std;
const int N=200010;
int n,a[N],pos[N],seg[2*N];
const int INF=1<<29;
void build(int cur,int l,int r){//[l,r)
	if(l>r)return;
	if(l+1==r){
		seg[cur]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(cur<<1,l,m);
	build(cur<<1|1,m,r);
	seg[cur]=max(seg[cur<<1],seg[cur<<1|1]);
}
int query(int cur,int l,int r,int ql,int qr){
	if(l>r||qr<=l||r<=ql)return -INF;
	if(ql<=l&&r<=qr)return seg[cur];
	int m=(l+r)>>1;
	return max(
		query(cur<<1,l,m,ql,qr),
		query(cur<<1|1,m,r,ql,qr)
	);
}
int main(){
	cin>>n;
	int tmp;
	for(int i=1;i<=n;++i){
		cin>>tmp;
		a[i]=tmp;
		pos[tmp]=i;
	}
	build(1,1,n+1);
	int l=1,r=n+1,next;
	while(l<r){
		next=pos[l];
	}
}
