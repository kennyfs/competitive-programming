#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <iostream>
#include <utility>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int t,n,m,tmp;
int pre[201][201],b[201];
pii frt[201];
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(register int i=1;i<=n;++i){
			pre[i][0]=0;
			for(register int j=1;j<=m;++j){
				cin>>tmp;
				pre[i][j]=pre[i][j-1]+(tmp?-1:1);
			}
		}
		int ans=0;
		for(register int i=1;i<=m;++i){
			for(register int j=i;j<=m;++j){
				frt[0]={0,0};
				for(register int k=1;k<=n;++k){
					frt[k]={frt[k-1].F+pre[k][j]-pre[k][i-1],k};
				}
				sort(frt,frt+n+1);
				int best=0,sec=-1;
				for(register int k=1;k<=n;++k){
					if(frt[k].F-frt[best].F>0){
						if(frt[k].S>frt[best].S)ans=max(ans,(frt[k].S-frt[best].S)*(j-i+1));
					}else{
						if(sec!=-1&&frt[k].S>frt[sec].S)ans=max(ans,(frt[k].S-frt[sec].S)*(j-i+1));
					}
					if(frt[k].S<frt[best].S){
						if(frt[k].F>frt[best].F)sec=best;
						best=k;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}
