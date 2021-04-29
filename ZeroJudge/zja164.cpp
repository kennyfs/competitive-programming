#include <iostream>
#include <tuple>
#include <utility>
#define Hirasawa_Yui_my_wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 80000000
using namespace std;
int n,q;
const int N=200005;
int data[N],sum[4*N],front[4*N],back[4*N],findex[4*N],bindex[4*N],mid[4*N],Lindex[4*N],Rindex[4*N];
void build(int cur,int l,int r){
	if(l>=r)return;
	if(l+1==r){
		sum[cur]=front[cur]=back[cur]=mid[cur]=data[l];
		findex[cur]=bindex[cur]=Lindex[cur]=Rindex[cur]=l;
		return;
	}
	int m=(l+r)>>1;
	build(cur<<1  ,l,m);
	build(cur<<1|1,m,r);
	
	sum[cur]=sum[cur<<1]+sum[cur<<1|1];
	mid[cur]=max(back[cur<<1]+front[cur<<1|1],max(mid[cur<<1],mid[cur<<1|1]));
	if(mid[cur]==mid[cur<<1|1])
		Lindex[cur]=Lindex[cur<<1|1],
		Rindex[cur]=Rindex[cur<<1|1];
	if(mid[cur]==back[cur<<1]+front[cur<<1|1])
		Lindex[cur]=bindex[cur<<1],
		Rindex[cur]=findex[cur<<1|1];
	if(mid[cur]==mid[cur<<1])
		Lindex[cur]=Lindex[cur<<1],
		Rindex[cur]=Rindex[cur<<1];
	
	front[cur]=sum[cur<<1]+front[cur<<1|1];
	findex[cur]=findex[cur<<1|1];
	if(front[cur<<1]>=front[cur])front[cur]=front[cur<<1],findex[cur]=findex[cur<<1];
	
	back[cur]=back[cur<<1|1];
	bindex[cur]=bindex[cur<<1|1];
	if(sum[cur<<1|1]+back[cur<<1]>=back[cur])back[cur]=sum[cur<<1|1]+back[cur<<1],bindex[cur]=bindex[cur<<1];
}
int f,fl;
int ans,ansl,ansr;
int toupdate;
void query(int cur,int l,int r,int ql,int qr){
	if(l>=r||r<=ql||qr<=l)return;
	if(ql<=l&&r<=qr){
		/*compare:
			f+front[cur]
			mid[cur]
		  and then update ans
		*/
		toupdate=max(f+front[cur],mid[cur]);
		//[fl,findex[cur]]   and   [Lindex[cur],Rindex[cur]]
		if(toupdate>ans){
			ans=toupdate;
			if(toupdate==mid[cur])
				ansl=Lindex[cur],ansr=Rindex[cur];
			if(toupdate==f+front[cur])
				ansl=fl,ansr=findex[cur];
		}
		//update f, fl
		if(back[cur]>f+sum[cur])f=back[cur],fl=bindex[cur];
		else if(f+sum[cur]>=0)f=f+sum[cur];//if f+sum[cur]==0, don't update because ans(l,r) l,r should be the least
		else f=0,fl=r;
		return;
	}
	if(l+1==r)return;
	int m=(l+r)>>1;
	query(cur<<1  ,l,m,ql,qr);
	query(cur<<1|1,m,r,ql,qr);
}
int main(){
	Hirasawa_Yui_my_wife
	int i=1;
	int l,r;
	while(cin>>n>>q){
		cout<<"Case "<<i++<<":\n";
		for(int i=1;i<=n;++i)cin>>data[i];
		build(1,1,n+1);
		while(q--){
			ans=-INF;
			cin>>l>>r;
			f=0;fl=l;
			query(1,1,n+1,l,r+1);
			cout<<ansl<<' '<<ansr<<' '<<ans<<'\n';
		}
	}
}
