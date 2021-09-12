#pragma GCC optimize(2)
#pragma GCC optimize("inline")
#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstring>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=500+10,INF=1<<30;
int n;
int a[N][N],mx[N],my[N],lx[N],ly[N],slack[N];
bool vx[N],vy[N],check[N];
bool dfs(int u,bool ch){
	if(vx[u])return 0;
	vx[u]=1;
	for(int v=0;v<n;++v){
		slack[v]=min(slack[v],lx[u]+ly[v]-a[u][v]);
		if(lx[u]+ly[v]>a[u][v])continue;
		vy[v]=1;
		if(my[v]==-1||dfs(my[v],ch)){
			if(ch)mx[u]=v,my[v]=u;
			return 1;
		}
	}
	return 0;
}
int delta;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	int INT=sizeof(n);
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>a[i][j];
	memset(lx,0,INT*(n+5));
	memset(ly,0,INT*(n+5));
	for(int x=0;x<n;++x){
		for(int y=0;y<n;++y){
			lx[x]=max(lx[x],a[x][y]);
		}
	}
	memset(mx,-1,INT*(n+5));
	memset(my,-1,INT*(n+5));
	for(int i=0;i<n;++i){
		memset(vx,0,n+5);
		memset(vy,0,n+5);
		memset(check,0,n+5);
		fill(slack,slack+n+5,INF);
		check[i]=1;
		bool flag=0;
		while(!flag){
			for(int x=0;x<n;++x){
				if(check[x]&&dfs(x,0)){
					flag=1;
					break;
				}
			}
			if(flag)break;
			delta=INF;
			for(int y=0;y<n;++y)if(!vy[y])delta=min(delta,slack[y]);
			memset(check,0,n+5);
			for(int j=0;j<n;++j){
				if(vx[j])lx[j]-=delta;
				if(vy[j])ly[j]+=delta;
				else{
					slack[j]-=delta;
					if(slack[j]==0){//new tight edge
						if(my[j]==-1){//find new augmenting path in G', break (but still need to update remain lx and ly)
							flag=1;
						}else{
							check[my[j]]=1;//skip some path
						}
					}
				}
			}
		}
		memset(vx,0,n+5);
		memset(vy,0,n+5);
		dfs(i,1);
	}
	int ans=0;
	for(int i=0;i<n;i++)ans+=lx[i]+ly[i];
	cout<<ans<<'\n';
	for(int i=0;i<n;i++)cout<<lx[i]<<' ';
	cout<<'\n';
	for(int i=0;i<n;i++)cout<<ly[i]<<' ';
	cout<<'\n';
}
//帶權二分圖匹配，超難
//TOI
