#include <unistd.h>
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
inline void W(int n){static char buf[12],p;if(n==0)OB[OP++]='0';p=0;while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];OB[OP++]='\n';if(OP>65516)write(1,OB,OP),OP=0;}
#define wiwiho 25
using namespace std;
int const N=1e6+10,inf=8e7*wiwiho;
int n,a[N],seg[4*N];
inline int min(int a,int b){
	return a>b?b:a;
}
void build(int cur,int l,int r){
	if(l>=r)return;
	if(l+1==r){seg[cur]=a[l];return;}
	int m=l+r>>1;
	build(cur<<1,l,m);
	build(cur<<1|1,m,r);
	seg[cur]=min(seg[cur<<1],seg[cur<<1|1]);
}
int query(int cur,int l,int r,int ql,int qr){
	if(l>=r||r<=ql||qr<=l)return inf;
	if(ql<=l&&r<=qr)return seg[cur];
	int m=l+r>>1;
	return min(query(cur<<1,l,m,ql,qr),query(cur<<1|1,m,r,ql,qr));
}
int main(){
	n=R();
	for(int i=1;i<=n;++i)a[i]=R();
	build(1,1,n+1);
	for(int i=1,l,r;i<=n;++i){
		l=R();
		r=R();
		W(query(1,1,n+1,l,r+1)+1);
	}
	write(1,OB,OP);
}