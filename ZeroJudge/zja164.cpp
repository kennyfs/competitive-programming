#include <iostream>
#include <tuple>
#include <utility>
using namespace std;
int n,q;
const int N=200005;
int data[N],sum[4*N],front[4*N],back[4*N],findex[4*N],bindex[4*N],mid[4*N],lindex[4*N],rindex[4*N];
void build(int cur,int l,int r){
	cout<<l<<' '<<r<<'\n';
	if(l>=r)return;
	if(l+1==r){
		sum[cur]=front[cur]=back[cur]=mid[cur]=data[l];
		findex[cur]=bindex[cur]=lindex[cur]=rindex[cur]=l;
		return;
	}
	int m=(l+r)>>1;
	cout<<"flag2\n";
	build(cur<<1  ,l,m);
	build(cur<<1|1,m,r);
	
	sum[cur]=sum[cur<<1]+sum[cur<<1|1];
	mid[cur]=max(back[cur<<1]+front[cur<<1|1],max(mid[cur<<1],mid[cur<<1|1]));
	if(mid[cur]==mid[cur<<1|1])
		lindex[cur]=lindex[cur<<1|1],
		rindex[cur]=rindex[cur<<1|1];
	if(mid[cur]==back[cur<<1]+front[cur<<1|1])
		lindex[cur]=bindex[cur<<1],
		rindex[cur]=findex[cur<<1|1];
	if(mid[cur]==mid[cur<<1])
		lindex[cur]=lindex[cur<<1],
		rindex[cur]=rindex[cur<<1];
	
	front[cur]=front[cur<<1];
	findex[cur]=findex[cur<<1];
	if(sum[cur<<1]+front[cur<<1|1]>front[cur])front[cur]=sum[cur<<1]+front[cur<<1|1],findex[cur]=findex[cur<<1|1];
	
	back[cur]=back[cur<<1|1];
	bindex[cur]=bindex[cur<<1|1];
	if(sum[cur<<1|1]+back[cur<<1]>back[cur])back[cur]=sum[cur<<1|1]+back[cur<<1],bindex[cur]=bindex[cur<<1];
	cout<<"leave"<<l<<' '<<r<<'\n';return;
}
int f,fl;
int ans,ansl,ansr;
int toupdate;
void query(int cur,int l,int r,int ql,int qr){
	if(l>=r||r<=ql||qr<=l)return;
	if(l>=ql&&r<=qr){
		/*compare:
			f+front[cur]
			mid[cur]
		  and then update ans
		*/
		toupdate=max(f+front[cur],mid[cur]);
		//[fl,findex[cur]]   and   [lindex[cur],rindex[cur]]
		if(toupdate>ans){
			if(toupdate==mid[cur])
				ansl=lindex[cur],ansr=rindex[cur];
			if(toupdate==f+front[cur])
				ansl=fl,ansr=findex[cur];
		}
		
		//update f, fl
		if(back[cur]>f+sum[cur])f=back[cur],fl=bindex[cur];
		else if(f+sum[cur]>=0)f=f+sum[cur];//if f+sum[cur]==0, don't update because ans(l,r) l,r should be the least
		else f=0,fl=r;
	}
	int m=(l+r)>>1;
	query(cur<<1  ,l,m,ql,qr);
	query(cur<<1|1,m,r,ql,qr);
}
int main(){
	int i=1;
	while(cin>>n>>q){
		cout<<"Case "<<i++<<":\n";
		for(int i=1;i<=n;++i)cin>>data[i];
		build(1,1,n+1);
		cout<<"flag1"<<endl;
		query(1,1,n+1,1,3);
		cout<<ansl<<' '<<ansr<<' '<<ans<<'\n';
	}
}
