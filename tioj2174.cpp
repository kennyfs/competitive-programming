#include <iostream>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define Min first
#define Count second
#define infinity 8e7
using namespace std;
const int N=3e5;
int n,q,q1=0,q2=0;
int segm[4*N+20],segc[4*N+20],lazy[4*N+20];//min and count
//seg for time
//need add in a range[l,r]
struct op1{
	int pos,x,t;
	void set(int pp,int xx,int tt){pos=pp,x=xx,t=tt;}
} data1l[N],data1r[N];
struct op2{
	int pos,t;
	void set(int pp,int tt){pos=pp,t=tt;}
} data2[N];
inline bool op1cmp(op1 a,op1 b){return a.pos<b.pos;}
inline bool op2cmp(op2 a,op2 b){return a.pos<b.pos;}
ostream &operator<<(std::ostream &os,op1 const &m){
	return os<<m.pos<<','<<m.x<<','<<m.t;
}
ostream &operator<<(std::ostream &os,op2 const &m){
	return os<<m.pos<<','<<m.t;
}
void push(int cur,int l,int r){
	segm[cur]+=lazy[cur];
	if(l+1<r)
		lazy[cur<<1]=lazy[cur<<1|1]=lazy[cur];
	lazy[cur]=0;
}
void pull(int cur,int l,int r){//we promise that sons are pushed
	int R=segm[cur<<1],L=segm[cur<<1|1];
	if(L>R)segm[cur]=R,segc[cur]=segc[cur<<1];
	else if(L==R)segm[cur]=R,segc[cur]=segc[cur<<1]+segc[cur<<1|1];
	else segm[cur]=L,segc[cur]=segc[cur<<1|1];
}
void add(int cur,int l,int r,int ql,int qr,int val){
	if(l>=r||r<=ql||qr<=l)return;
	push(cur,l,r);
	if(ql<=l&&r<=qr){
		lazy[cur]+=val;
		return;
	}
	int m=(l+r)>>1;
	add(cur<<1,l,m,ql,qr,val);
	add(cur<<1|1,m,r,ql,qr,val);
	push(cur<<1,l,m);push(cur<<1|1,m,r);
	pull(cur,l,r);
}
pii query(int cur,int l,int r,int ql,int qr){//
	if(l>=r||r<=ql||qr<=l)return {infinity,0};
	cout<<"query,l="<<l<<",r"<<r<<'\n';
	push(cur,l,r);
	if(ql<=l&&r<=qr)
		return {segm[cur],segc[cur]};
	int m=(l+r)>>1;
	pii L=query(cur<<1,l,m,ql,qr),R=query(cur<<1|1,m,r,ql,qr);
	if(L.Min<R.Min){cout<<"flag 1\n";return {L.Min,L.Count};}
	else if(L.Min>R.Min){cout<<"flag 2\n";return {R.Min,R.Count};}
	else if(L.Min!=infinity){cout<<"flag 3\n";return {L.Min,segc[cur<<1]+segc[cur<<1|1]};}
	return {infinity,0};
}
void init(int cur,int l,int r){
	segm[cur]=0;
	segc[cur]=r-l;
	int m=(l+r)>>1;
	if(l+1<r)
		init(cur<<1,l,m),
		init(cur<<1|1,m,r);
}
int main(){
	init(1,0,N);
	fill(lazy,lazy+4*N+20,0);
	cin>>n>>q;
	int op,tr,tl,tx,t=0;
	q1=q2=0;
	while(q--){
		cin>>op;
		if(op==1){
			cin>>tl>>tr>>tx;
			data1l[q1].set(tl,tx,t);
			data1r[q1].set(tr,tx,t);
			++q1;
			++t;
		}else{
			cin>>tx;
			data2[q2++].set(tx,t++);
		}
	}
	sort(data1l,data1l+q1,op1cmp);
	sort(data1r,data1r+q1,op1cmp);
	sort(data2,data2+q2,op2cmp);
	//input completed
	//do operation in scan line for pos in [0,n)
	int indl=0,indr=0,indq=0;
	auto l=data1l[indl],r=data1r[indr];
	auto q=data2[indq];
	//indl,indr are [0,q1) l and r is ll[either one], and x is xx[either one]
	//and time is t1[either one]
	
	//indq is [0,q2)
	//and time is t2[indq]
	while(indr<q1||indq<q2){
		//cout<<indr<<','<<indl<<','<<indq<<"q1:"<<q1<<','<<q2<<'\n';
		if((indl<q1 && l.pos<=r.pos&&l.pos<=q.pos)||(indr>=q1&&indq>=q2)){//if l==q then do left first
			cout<<"L\n";
			add(1 ,0,N ,l.t,N ,l.x);
			l=data1l[++indl];
			//xaxis goes to ll[indl]
		}else if((indr<q1 && r.pos<=l.pos&&r.pos<q.pos)||(indl>=q1&&indq>=q2)){//if r==q then do query first
			cout<<"R\n";
			add(1 ,0,N ,r.t,N ,r.x);
			r=data1r[++indr];
			//xaxis goes to rr[indr]
		}else{//do query
			cout<<"Q\nq.t="<<q.t<<"\n";
			pii res=query(1,0,N,0,q.t);
			if(!res.Min)cout<<res.Count<<'\n';
			//else cout<<"0\n";
			q=data2[++indq];
		}
	}
}
