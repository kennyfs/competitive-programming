#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,q;
int sorted[100010],tree[20][100010],toleft[20][100010];//toleft as BIT
void BITaddone(int dep,int ind){
	for(int i=ind;i<=n;i+=i&(-i))
		++toleft[dep][i];
}
int BITquery(int dep,int ind){
	int ans=0;
	for(int i=ind;i;i-=i&(-i))
		ans+=toleft[dep][i];
	return ans;
}
void build(int l,int r,int dep){//build tree[dep] with tree[dep-1]
	//[l,r)
	if(l+1==r)return;
	int m=(l+r)>>1,mid=sorted[m-1];//[l,m) and [m,r)
	int same=0;//the num of numbers that will go to left subtree and are equal to sorted[m-1]
	for(int i=m-1;i>=l;--i){//reverse search in [l,m)
		if(sorted[i]==mid)
			++same;
		else
			break;
	}
	int cursame=0,lind=l,rind=m;
	bool left;
	for(int i=l;i<r;++i){
		if(tree[dep-1][i]<mid){
			left=1;
		}else if(tree[dep-1][i]==mid){
			if(cursame<=same)//go to left
				left=1;
			else
				left=0;
			++cursame;
		}else{
			left=0;
		}
		if(left)
			tree[dep][lind++]=tree[dep-1][i],
			BITaddone(dep-1,i);//add toleft[dep][i]
		else
			tree[dep][rind++]=tree[dep-1][i];
	}
	build(l,m,dep+1);
	build(m,r,dep+1);
}
int query(int l,int r,int ql,int qr,int dep,int k){
	if(l+1==r)return sorted[l];
	int m=(l+r)>>1;
	int lcnt=BITquery(dep,qr-1)-BITquery(dep,ql-1);//num of numbers in [ql,qr) that go to the left
	//int rcnt=qr-ql-lcnt;
	if(k<=lcnt){
		int newl=l+BITquery(dep,ql-1)-BITquery(dep,l-1);//we don't need the nums in [l,ql) that go to the left
		int	newr=newl+lcnt;
		return query(l,m,newl,newr,dep+1,k);
	}else{
		int newr=qr+BITquery(dep,r-1)-BITquery(dep,qr-1);//we don't need the nums in [qr,r) that go to the "right"
		//r-((r-qr)-(BITquery(dep,r-1)-BITquery(dep,qr-1)))  =  qr+BITquery(dep,r-1)-BITquery(dep,qr-1)
		int newl=newr-(ql-qr-lcnt);
		return query(m,r,newl,newr,dep+1,k-lcnt);
	}
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>tree[0][i],sorted[i]=tree[0][i];
	sort(sorted+1,sorted+n+1);
	fill(&toleft[0][0],&toleft[0][0]+sizeof(toleft)/sizeof(toleft[0][0]),0);
	
	build(1,n+1,1);
	int x,y,k;
	while(q--){
		cin>>x>>y>>k;
		cout<<query(1,n+1,x,y+1,0,k)<<'\n';
	}
}
