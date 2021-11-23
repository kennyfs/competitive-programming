#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
#define mp make_pair
#define m ((l+r)>>1)
#define pii pair<int,int>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2e5+10;
int n,q;
int a[4][N];
float times[4]={0,0.36,0.54,0.1};
int seg[4][4*N],seg2[4][4*N],lzadd[4][4*N],lzmod[4][4*N];
bool mod[4][4*N],mod2[4][4*N];
pii operator+(pii a,pii b){
	return mp(a.first+b.first,a.second+b.second);
}
void push(int s,int cur,int l,int r){
	if(!mod[s][cur]&&!lzadd[s][cur])return;
	if(mod[s][cur]){
		seg[s][cur]=lzmod[s][cur]*(r-l);
		seg2[s][cur]=lzmod[s][cur]*seg[s][cur];
		lzmod[s][cur<<1]=lzmod[s][cur<<1|1]=lzmod[s][cur];
		mod[s][cur<<1]=mod[s][cur<<1|1]=1;
		lzadd[s][cur<<1]=lzadd[s][cur<<1|1]=0;
	}
	if(lzadd[s][cur]){
		seg2[s][cur]+=2*seg[s][cur]*lzadd[s][cur]+(r-l)*lzadd[s][cur]*lzadd[s][cur];
		seg[s][cur]+=lzadd[s][cur]*(r-l);
		lzadd[s][cur<<1]+=lzadd[s][cur];
		lzadd[s][cur<<1|1]+=lzadd[s][cur];
	}
	lzadd[s][cur]=0;mod[s][cur]=0;lzmod[s][cur]=0;
}
void pull(int s,int cur){
    seg[s][cur]=seg[s][cur<<1]+seg[s][cur<<1|1];
    seg2[s][cur]=seg2[s][cur<<1]+seg2[s][cur<<1|1];
}
void build(int s,int cur,int l,int r){
    if(l>=r)return;
    if(l+1==r){
        seg[s][cur]=a[s][l];
        seg2[s][cur]=a[s][l]*a[s][l];
        return;
    }
    build(s,cur<<1,l,m);
    build(s,cur<<1|1,m,r);
    seg[s][cur]=seg[s][cur<<1]+seg[s][cur<<1|1];
    seg2[s][cur]=seg2[s][cur<<1]+seg2[s][cur<<1|1];
}
pii query(int s,int cur,int l,int r,int ql,int qr){//sum,sum2
	if(l>=r||r<=ql||qr<=l)return mp(0,0);
	push(s,cur,l,r);
	if(ql<=l&&r<=qr){
		return mp(seg[s][cur],seg2[s][cur]);
	}
	return query(s,cur<<1,l,m,ql,qr)+query(s,cur<<1|1,m,r,ql,qr);
}
void add(int s,int cur,int l,int r,int ql,int qr,int x){
	if(l>=r||r<=ql||qr<=l)return;
	push(s,cur,l,r);
	if(ql<=l&&r<=qr) {
		lzadd[s][cur]+=x;
		return;
	}
	add(s,cur<<1,l,m,ql,qr,x);
	add(s,cur<<1|1,m,r,ql,qr,x);
	push(s,cur<<1,l,m);
	push(s,cur<<1|1,m,r);
	seg[s][cur]=seg[s][cur<<1]+seg[s][cur<<1|1];
    seg2[s][cur]=seg2[s][cur<<1]+seg2[s][cur<<1|1];
}
void modi(int s,int cur,int l,int r,int ql,int qr,int x){
	if(l>=r||r<=ql||qr<=l)return;
	push(s,cur,l,r);
	if(ql<=l&&r<=qr) {
		lzadd[s][cur]=0;
		lzmod[s][cur]=x;
		mod[s][cur]=1;
		return;
	}
	modi(s,cur<<1,l,m,ql,qr,x);
	modi(s,cur<<1|1,m,r,ql,qr,x);
	push(s,cur<<1,l,m);
	push(s,cur<<1|1,m,r);
	seg[s][cur]=seg[s][cur<<1]+seg[s][cur<<1|1];
    seg2[s][cur]=seg2[s][cur<<1]+seg2[s][cur<<1|1];
}
int op,l,r,s,x;
double sum,sum2,ans,single,mu,dev;
signed main(){
    Hirasawa_Yui_My_Wife
	cin>>n>>q;
	for(int i=1;i<=3;++i){
		for(int j=1;j<=n;++j)cin>>a[i][j];
		build(i,1,1,n+1);
	}
	cout<<setprecision(1)<<fixed;
	while(q--){
		cin>>op;
		switch(op){
			case 1:
				cin>>l>>r>>x;
				ans=0;
				for(int i=1;i<=3;++i){
					pii res=query(i,1,1,n+1,l,r+1);
					sum=res.first;
					sum2=res.second;
					single=query(i,1,1,n+1,x,x+1).first;
					mu=sum/(r-l+1);
					dev=sqrt(sum2/(r-l+1)-mu*mu);
					if(dev!=0)ans+=(single-mu)/dev*times[i];
				}
				cout<<50+10*ans<<'\n';
				break;
			case 2:
				cin>>l>>r>>s>>x;
				add(s,1,1,n+1,l,r+1,x);
				break;
			case 3:
				cin>>l>>r>>s>>x;
				modi(s,1,1,n+1,l,r+1,x);
				break;
		}
	}
}
