#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int N=8e5;
int n;
int seg[4*N+20],segmin[4*N+20],lazyadd[4*N+20],lazyedit[4*N+20];//seg is max
//if lazyedit>0 then add, otherwise (==0) don't do anything
void push(int cur,int l,int r){
	if(lazyedit[cur])seg[cur]=segmin[cur]=lazyedit[cur];
	seg[cur]+=lazyadd[cur];
	segmin[cur]+=lazyadd[cur];
	if(l+1!=r){
		if(lazyedit[cur])//edit sons and set sons' add
			lazyedit[cur<<1]=lazyedit[cur<<1|1]=lazyedit[cur],
			lazyadd[cur<<1]=lazyadd[cur<<1|1]=0;
		lazyadd[cur<<1]+=lazyadd[cur];
		lazyadd[cur<<1|1]+=lazyadd[cur];
	}
	lazyedit[cur]=0;
	lazyadd[cur]=0;
}
void pull(int cur,int l,int r){//we promise that sons are pushed
	if(l+1==r)return;
	seg[cur]=max(seg[cur<<1],seg[cur<<1|1]);
	segmin[cur]=min(segmin[cur<<1],segmin[cur<<1|1]);
}
void seg_add(int cur,int l,int r,int ql,int qr,int val){
	if(l>=r||r<=ql||qr<=l)return;
	push(cur,l,r);
	if(ql<=l&&r<=qr){
		lazyadd[cur]+=val;
		return;
	}
	//if l+1==r, it must have been returned. (it must be either in the range or out of range)
	int m=l+r>>1;
	seg_add(cur<<1,l,m,ql,qr,val);
	seg_add(cur<<1|1,m,r,ql,qr,val);
	push(cur<<1,l,m);push(cur<<1|1,m,r);
	pull(cur,l,r);
}
void seg_max(int cur,int l,int r,int ql,int qr,int val){
	if(l>=r||r<=ql||qr<=l)return;
	push(cur,l,r);
	//cout<<"seg max:: l:"<<l<<",r:"<<r<<",val:"<<val<<",segmin:"<<segmin[cur]<<'\n';
	if(l>=ql&&qr>=r){
		if(seg[cur]<=val){
			lazyedit[cur]=val;
			//cout<<"case 1\n";
			return;
		}
	}
	int m=l+r>>1;
	if(segmin[cur<<1]<val)
		seg_max(cur<<1,l,m,ql,qr,val);
	if(segmin[cur<<1|1]<val)
		seg_max(cur<<1|1,m,r,ql,qr,val);
	pull(cur,l,r);
}
int seg_query(int cur,int l,int r,int ql,int qr){//query max
	if(l>=r||r<=ql||qr<=l)return -8e7;
	push(cur,l,r);
	if(l>=ql&&qr>=r)return seg[cur];//already pushed
	int m=l+r>>1;
	return max(seg_query(cur<<1,l,m,ql,qr),seg_query(cur<<1|1,m,r,ql,qr));
}
main(){
    Hirasawa_Yui_My_Wife
	fill(seg,seg+4*N+20,0);
	fill(lazyadd,lazyadd+4*N+20,0);
	fill(lazyedit,lazyedit+4*N+20,0);

	cin>>n;
	int a,b;
	for(int i=1;i<=n;++i){//[0,n)
		cin>>a>>b;//a,b are 0-based
		seg_add(1,0,n,a,b+1,1);//[a,b] +=1
		if(b+1<n)seg_max(1,0,n,b+1,n,seg_query(1,0,n,b,b+1));
		//set[b+1,n] with max of [0,b]
		/*
		cout<<i<<'\n';
		for(int j=0;j<n;++j)cout<<j<<":"<<seg_query(1,0,n,j,j+1)<<'\n';
		*/
	}
	cout<<seg_query(1,0,n,n-1,n)<<'\n';
}
