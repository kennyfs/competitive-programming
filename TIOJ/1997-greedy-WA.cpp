#include <iostream>
#define int long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1000010;
const int INF=1000000000000000000;
int n,k,data[N];
int posmax[4*N],posmin[4*N];
void build(int cur,int l,int r){
	if(l+1==r){
		posmax[cur]=posmin[cur]=l;
		return;
	}
	int m=(l+r)>>1;
	build(cur<<1,l,m);
	build(cur<<1|1,m,r);
	posmax[cur]=posmax[cur<<1];
	posmin[cur]=posmin[cur<<1];
	if(data[posmax[cur<<1|1]]>data[posmax[cur]])posmax[cur]=posmax[cur<<1|1];
	if(data[posmin[cur<<1|1]]<data[posmin[cur]])posmin[cur]=posmin[cur<<1|1];
}
int querymax(int cur,int l,int r,int ql,int qr){
	//if(cur==1)cout<<"max "<<ql<<' '<<qr;
	if(qr<=l||r<=ql)return 1000008;
	if(r<=qr&&ql<=l)return posmax[cur];
	int m=(l+r)>>1;
	int ans=querymax(cur<<1,l,m,ql,qr),tmp=querymax(cur<<1|1,m,r,ql,qr);
	if(data[ans]<data[tmp])ans=tmp;
	return ans;
}
int querymin(int cur,int l,int r,int ql,int qr){
	//if(cur==1)cout<<"min "<<ql<<' '<<qr;
	if(qr<=l||r<=ql)return 1000009;
	if(r<=qr&&ql<=l)return posmin[cur];
	int m=(l+r)>>1;
	int ans=querymin(cur<<1,l,m,ql,qr),tmp=querymin(cur<<1|1,m,r,ql,qr);
	if(data[tmp]<data[ans])ans=tmp;
	return ans;
}
main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>k;
	cin>>data[0];
	for(int i=1;i<n;++i)cin>>data[i],data[i]+=data[i-1];
	if(k==1){cout<<data[n-1]<<'\n';return 0;}
	data[1000009]=INF;data[1000008]=-INF;
	build(1,0,n);
	
	if(k==2){
		cout<<querymax(1,0,n,0,n)+1<<'\n';
		return 0;
	}
	if(k>2)return 0;
	bool p;
	int best=-INF,sum,bestcut[10],cut[10];//only use 1 to 5
	fill(cut,cut+10,1);
	cut[k]=n;
	sum=(k%2)?data[n-1]-2*data[0]:-data[n-1]+2*data[0];
	while(1){
		bool move=0;
		p=k%2;
		for(int i=k-1;i;--i){
			p=!p;
			int ans;
			if(cut[i]+1==cut[i+1])continue;
			if(p){
				ans=querymax(1,0,n,cut[i],cut[i+1]-1);//cout<<" = "<<ans<<'\n';
				if(ans>=1000008)continue;
				sum+=2*(data[ans]-data[cut[i]-1]);//add [cut[i],ans]
				cut[i]=ans+1;
				move=1;
			}else{
				ans=querymin(1,0,n,cut[i],cut[i+1]-1);//cout<<" = "<<ans<<'\n';
				if(ans>=1000008)continue;
				sum-=2*(data[ans]-data[cut[i]-1]);//cout<<"minus "<<2*(data[ans]-data[cut[i]-1])<<'\n';
				cut[i]=ans+1;
				move=1;
			}
			//cout<<"sum="<<sum<<'\n';
		}
		if(!move)break;
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
		}/*
		for(int i=1;i<k;++i){
			cout<<cut[i]<<' ';
		}
		cout<<sum<<'\n';*/
	}
	for(int i=1;i<k;++i)cout<<bestcut[i]<<'\n';
	//cout<<best;
}
//自以為是的greedy唬爛解，WA，待解決
