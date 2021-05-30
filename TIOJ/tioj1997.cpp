#include <iostream>
#include <utility>
#define pii pair<int,int>
using namespace std;
const int N=1000010;
const int INF=1<<30;
int n,k,data[N];
int segmax[4*N],segmin[4*N],posmax[4*N],posmin[4*N];
void build(int cur,int l,int r){
	if(l+1==r){
		segmax[cur]=segmin[cur]=data[l];
		posmax[cur]=posmin[cur]=l;
		return;
	}
	int m=(l+r)>>1;
	build(cur<<1,l,m);
	build(cur<<1|1,m,r);
	segmax[cur]=segmax[cur<<1];posmax[cur]=posmax[cur<<1];
	segmin[cur]=segmin[cur<<1];posmin[cur]=posmin[cur<<1];
	if(segmax[cur<<1|1]>segmax[cur])segmax[cur]=segmax[cur<<1|1],posmax[cur]=posmax[cur<<1|1];
	if(segmin[cur<<1|1]<segmin[cur])segmin[cur]=segmin[cur<<1|1],posmin[cur]=posmin[cur<<1|1];
}
pii querymax(int cur,int l,int r,int ql,int qr){
	if(cur==1)cout<<"max "<<ql<<' '<<qr<<'\n';
	if(qr<=l||r<=ql)return {-INF,-1};
	if(r<=qr&&ql<=l)return {segmax[cur],posmax[cur]};
	int m=(l+r)>>1;
	pii ans=querymax(cur<<1,l,m,ql,qr),tmp=querymax(cur<<1|1,m,r,ql,qr);
	if(tmp>ans)ans=tmp;
	return ans;
}
pii querymin(int cur,int l,int r,int ql,int qr){
	if(cur==1)cout<<"min "<<ql<<' '<<qr<<'\n';
	if(qr<=l||r<=ql)return {INF,-1};
	if(r<=qr&&ql<=l)return {segmin[cur],posmin[cur]};
	int m=(l+r)>>1;
	pii ans=querymin(cur<<1,l,m,ql,qr),tmp=querymin(cur<<1|1,m,r,ql,qr);
	if(tmp<ans)ans=tmp;
	return ans;
}
ostream& operator<<(ostream& s,pii test){
	s<<test.first<<' '<<test.second;
	return s;
}
int main(){
	cin>>n>>k;
	cin>>data[0];
	for(int i=1;i<n;++i)cin>>data[i],data[i]+=data[i-1];
	build(1,0,n);
	bool p=!(k%2);
	int best=-INF,sum,bestcut[10],cut[10];//only use 1 to 5
	int count=0;
	fill(cut,cut+10,0);
	cut[k]=n;
	sum=(k%2)?data[n-1]:-data[n-1];
	while(cut[k-1]!=n-1){
		for(int i=1;i<k;++i){
			cout<<cut[i]<<' ';
		}
		cout<<'\n';
		p=!(k%2);
		for(int i=k-1;i;--i){
			pii ans;
			if(p){
				ans=querymax(1,0,n,cut[i],cut[i+1]);
				cout<<ans.second<<'\n';
				sum+=2*ans.first;
				cut[i]=ans.second+1;
			}else{
				ans=querymin(1,0,n,cut[i],cut[i+1]);
				cout<<ans.second<<'\n';
				sum-=2*ans.first;
				cut[i]=ans.second+1;
			}
			p=!p;
		}
		if(sum>best){
			bool flag=0;
			for(int i=1;i<k;++i){
				if(cut[i]==cut[i+1]){flag=1;break;}
			}
			if(!flag){
				for(int i=1;i<k;++i){
					bestcut[i]=cut[i];
				}
				best=sum;
			}
		}
		if(++count>10)break;
	}
	for(int i=1;i<k;++i)cout<<bestcut[i]<<'\n';
}
