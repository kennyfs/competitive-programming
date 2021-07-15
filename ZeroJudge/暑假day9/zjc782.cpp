#include <iostream>
#define Hirasawa_Yui_My_Wife
#define ll long long
using namespace std;
int const N=2000010;
int t,n,k;
int a[N],w[N],back[N];
inline int read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}
int main(){
	Hirasawa_Yui_My_Wife
	t=read();
	while(t--){
		n=read();k=read();
		for(int i=0;i<n;++i)a[i]=read();
		for(int i=0;i<n;++i)w[i]=read();
		w[n]=0;
		for(int i=n-1;i>=0;--i)back[i]=back[i+1]+w[i];
		int it=0;
		ll ans=0;
		for(int i=0;i<n;++i){
			while(it<n&&a[it]-a[i]<=k)++it;
			if(it==n)break;
			ans+=(ll)w[i]*(ll)back[it];
		}
		cout<<ans<<'\n';
	}
}
