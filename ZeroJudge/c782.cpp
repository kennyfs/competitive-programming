#pragma GCC optimize("Ofast")
#include <unistd.h>
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while(((c=RC())<'0'||c>'9')&&c!='-'&&c!=-1);if(c=='-'){a=0;while((c=RC())>='0'&&c<='9')a*=10,a-=c^'0';}else{a=c^'0';while((c=RC())>='0'&&c<='9')a*=10,a+=c^'0';}return a;}
#include <cstdio>
#include <deque>
#define Hirasawa_Yui_My_Wife
#define ll long long
int const N=2000010;
int t,n,k;
int a[N],w[N],back[N];
int main(){
	Hirasawa_Yui_My_Wife
	t=R();
	while(t--){
		n=R();k=R();
		for(int i=0;i<n;++i)a[i]=R();
		for(int i=0;i<n;++i)w[i]=R();
		w[n]=0;
		for(int i=n-1;i>=0;--i)back[i]=back[i+1]+w[i];
		int it=0;
		ll ans=0;
		for(int i=0;i<n;++i){
			while(it<n&&a[it]-a[i]<=k)++it;
			if(it==n)break;
			ans+=1ll*w[i]*back[it];
		}
		printf("%lld\n",ans);
	}
}
//輸入壓常才過得了的題
