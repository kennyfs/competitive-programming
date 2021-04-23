#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int N=1e5;
int n,q,data[N+5];
int seg[4*N+5],BIT[N+5];
int GCD(int a,int b){
	return b?GCD(b,a%b):a;
}
//seg tree and BIT are based on difference of data
//BIT
auto lowbit=[](int pos){return pos&(-pos);};
void bit_add(int pos,int val){
	for(;pos<=N;pos+=lowbit(pos))
		BIT[pos]+=val;
}
int bit_query(int pos){
	int ans=0;
	for(;pos>0;pos-=lowbit(pos))
		ans+=BIT[pos];
	return ans;
}
//seg tree
void seg_update(int cur){
	seg[cur]=GCD(seg[cur<<1],seg[cur<<1|1]);
}
void seg_build(int cur,int l,int r){
	if(l>=r)return;
	if(l+1==r){
		seg[cur]=data[l]-data[l-1];
		return;
	}
	int m=(l+r)>>1;
	seg_build(cur<<1,l,m);
	seg_build(cur<<1|1,m,r);
	seg_update(cur);
}
void seg_add(int cur,int l,int r,int pos,int val){//single point add
	//[l,r)
	if(pos>=r||pos<l)return;
	if(l+1==r){
		seg[cur]+=val;
		return;
	}
	int m=(l+r)>>1;
	if(pos<m)//right
		seg_add(cur<<1,l,m,pos,val);
	else
		seg_add(cur<<1|1,m,r,pos,val);
	seg_update(cur);
}
int seg_query(int cur,int l,int r,int ql,int qr){
	if(l>=r||r<=ql||l>=qr)return 0;
	if(l>=ql&&r<=qr)return seg[cur];
	int m=(l+r)>>1;
	int a=seg_query(cur<<1,l,m,ql,qr),b=seg_query(cur<<1|1,m,r,ql,qr);
	return GCD(a,b);
}
main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>data[i];
	}
	seg_build(1,1,n+1);
	int op,l,r,k;
	while(q--){
		cin>>op;
		if(op==1){
			cin>>l>>r>>k;//[l,r]
			bit_add(l,k);//add [l,n]
			seg_add(1,1,n+1,l,k);
			if(r+1<=n)//try to minus [r+1,n] if there's at least 1 element in [r+1,n]
				bit_add(r+1,-k),
				seg_add(1,1,n+1,r+1,-k);
		}else if(op==2){
			cin>>l>>r;//[l,r]
			//gcd(al,al+1...ar)=gcd(al,a(l+1)-al,ar-a(r-1))
			//difference #i:=ai-a(i-1)
			//seg_query(l,r):=gcd of difference [l,r)
			//so we need gcd(al,seg_query(l+1,r+1)), where al=original al+bit(l)
			cout<<abs(GCD(data[l]+bit_query(l),seg_query(1,1,n+1,l+1,r+1)))<<'\n';
		}
	}
}
