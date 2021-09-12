#include <iostream>
#include <unordered_map>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=2e5+10,C=(1<<23)+10;
int n,q,c;
unordered_map<int,int> mp;
int index=1;
int seg[2*24*N],segl[2*24*N],segr[2*24*N],lson[2*24*N],rson[2*24*N];//Qlog(2^24)*2*4
bool opened[2*24*N];
void update(int cur,int l,int r){
	int m=(l+r)>>1;
	bool L=lson[cur]&&opened[lson[cur]],R=rson[cur]&&opened[rson[cur]];
	if(!L&&!R){cout<<"FUCK"<<endl;return;}
	if(L&&R){
		seg[cur]=max(max(seg[lson[cur]],seg[rson[cur]]),segr[lson[cur]]+segl[rson[cur]]);
		segl[cur]=(seg[lson[cur]]==m-l)?m-l+segl[rson[cur]]:segl[lson[cur]];
		segr[cur]=(seg[rson[cur]]==r-m)?r-m+segr[lson[cur]]:segr[rson[cur]];
	}else if(L&&!R){
		seg[cur]=max(r-m+segr[lson[cur]],seg[lson[cur]]);
		segl[cur]=(seg[lson[cur]]==m-l)?r-l:segl[lson[cur]];
		segr[cur]=r-m+segr[lson[cur]];
	}else if(!L&&R){
		seg[cur]=max(m-l+segl[rson[cur]],seg[rson[cur]]);
		segl[cur]=m-l+segl[rson[cur]];
		segr[cur]=(seg[rson[cur]]==r-m)?r-l:segr[rson[cur]];
	}
}
void insert(int cur,int l,int r,int pos,int v){//if pos'll be this color v=0, otherwise v=1
	if(!opened[cur])opened[cur]=1;
	if(l+1==r){seg[cur]=segr[cur]=segl[cur]=v;return;}
	int m=(l+r)>>1;
	if(pos<m){
		if(!lson[cur])lson[cur]=index++;
		insert(lson[cur],l,m,pos,v);
	}else{
		if(!rson[cur])rson[cur]=index++;
		insert(rson[cur],m,r,pos,v);
	}
	update(cur,l,r);
}
int ans,f;
void query(int cur,int l,int r,int ql,int qr){
	if(qr<=l||r<=ql)return;
	if(ql<=l&&r<=qr){
		if(opened[cur]){
			ans=max(ans,f+segl[cur]);
			ans=max(ans,seg[cur]);
			//update f
			if(seg[cur]==r-l)f+=r-l;
			else f=segr[cur];
		}else{
			f+=r-l;
			ans=max(ans,f);
		}
		return;
	}
	int m=(l+r)>>1;
	query(lson[cur]?lson[cur]:index,l,m,ql,qr);
	query(rson[cur]?rson[cur]:index,m,r,ql,qr);
}
int color[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>q>>c;
	int T;
	for(int i=0;i<n;++i){
		cin>>T;
		color[i]=T;
		if(!mp.count(T))mp[T]=index++;
		insert(mp[T],0,C,i,0);
	}
	bool op;
	int p,x,y,k;
	while(q--){
		cin>>op;
		if(op){
			cin>>x>>y>>k;
			if(!mp.count(k)){cout<<y-x<<'\n';continue;}
			ans=f=0;
			query(mp[k],0,C,x,y);
			cout<<ans<<'\n';
		}else{
			cin>>p>>k;
			insert(mp[color[p]],0,C,p,1);
			color[p]=k;
			if(!mp.count(k))mp[k]=index++;
			insert(mp[k],0,C,p,0);
		}
	}
}
//毒瘤的陣列動態開點www
