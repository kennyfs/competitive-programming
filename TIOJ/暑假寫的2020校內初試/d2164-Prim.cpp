#include <iostream>
#define Hirasawa_Yui_My_Wife
#define ll long long
using namespace std;
int const N=5050;
ll const INF=1ll<<62;
inline int read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}
ll G[N][N];//因為是稠密圖所以用陣列存
int n;
int x[N],y[N],z[N];
bool vis[N];
ll dist[N];
int main(){
	Hirasawa_Yui_My_Wife
	n=read();
	for(int i=1;i<=n;++i){
		//cin>>x[i]>>y[i]>>z[i];
		x[i]=read();y[i]=read();z[i]=read();
	}
	ll a,b,c;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			a=x[i]-x[j];b=y[i]-y[j];c=z[i]-z[j];
			G[i][j]=G[j][i]=a*a+b*b+c*c;
		}
	}
	ll ans=0;
	ll mi;
	fill(dist,dist+N,INF);
	dist[1]=0;
	int now=1,next;
	for(int t=0;t<n;++t){
		ans+=dist[now];
		vis[now]=1;
		mi=INF;
		for(int i=2;i<=n;i++){if(vis[i])continue;
			dist[i]=min(dist[i],G[i][now]);
			if(dist[i]<mi){
				mi=dist[i];
				next=i;
			}
		}
		now=next;
	}
	cout<<ans<<'\n';
}
