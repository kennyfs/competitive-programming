#include <unistd.h>
const int mxbuf=65536;//預設65536，通常改低會有更好的表現
char OB[mxbuf]; int OP;
inline char RC(){static char buf[mxbuf],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,mxbuf))==buf?-1:*p++;}
//以下的R, W都支援負數
inline int R(){static char c;bool f=0;int a;while((c=RC())<'0'&&c!='-');if(c=='-')f=1,c=RC();a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return f?(-a):a;}
inline void W(int n){static char buf[12],p;if(n==0)OB[OP++]='0';p=0;if(n<0)n=-n,OB[OP++]='-';while(n)buf[p++]='0'+(n%10),n/=10;for(--p;p>=0;--p)OB[OP++]=buf[p];OB[OP++]='\n';if(OP>mxbuf-20)write(1,OB,OP),OP=0;}
#define ll long long
using namespace std;
const int M=998244353,N=2e5+10;
ll inv[N];
int n,a[N],BIT[N],E[N];
int madd(int x,int y){
    int a=x+y;
    if(a>=M)a-=M;
    return a;
}
void chmadd(int& x,int y){
    x+=y;
    if(x>=M)x-=M;
}
int query(int x){
    int ret=0;
    for(;x;x-=x&-x)chmadd(ret,BIT[x]);
    return ret;
}
void add(int x,int y){
    for(;x<=n;x+=x&-x)chmadd(BIT[x],y);
}
signed main(){
    inv[1]=1;
    for(int i=2;i<N;i++){
        inv[i]=(ll)(M-M/i)*inv[M%i]%M;
    }
    n=R();
    for(int i=1;i<n;i++)a[i]=R();
    int E;
    for(int i=n-1;i>=1;--i){
        E=(((ll)query(i+a[i])*inv[a[i]])%M+inv[a[i]]+1)%M;
        add(i,E);
    }
    W(E);
    write(1,OB,OP);
}