#include <bits/stdc++.h>
using namespace std;
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=1e3+10;
int n,m;
int x[N],y[N];
signed main(){
    Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>x[i];
	for(int i=1;i<=m;++i)cin>>y[i];
	int ans=-8e7;
	for(int i=-m+1;i<=n;++i){
		int xs=(i>1)?i:1,ys=(-i+1>1)?-i+1:1;
		int mi0=0,mi1=0;
		int pre0=0,pre1=0;
		for(;xs<=n&&ys<=m;++xs,++ys){
			pre0+=x[xs]*y[ys];
			if(pre0-mi0>ans)ans=pre0-mi0;
			if(mi0>pre0)mi0=pre0;
			pre1+=x[xs]*y[m-ys+1];
			if(pre1-mi1>ans)ans=pre1-mi1;
			if(mi1>pre1)mi1=pre1;
		}
	}
    cout<<ans;
}
