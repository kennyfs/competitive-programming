#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,m;
int g[55][55],up[55][55];
int tmpsum[55],dp[55];
int sum(int line,int u,int d){
	if(u>d)swap(u,d);
    return up[line][d]-up[line][u-1];
}
int main(){
	Hirasawa_Yui_My_Wife
    while(cin>>n>>m){
        for(int i=1;i<=n;++i){
            cin>>g[i][1];up[i][1]=g[i][1];
            for(int j=2;j<=m;++j){
                cin>>g[i][j];
                up[i][j]=up[i][j-1]+g[i][j];
            }
        }
        int best=-8e7;
        for(int i=1;i<=m;++i){
			for(int j=1;j<=i;++j){//[j,i]
				tmpsum[1]=dp[1]=sum(1,j,i);
				for(int k=2;k<=n;++k)tmpsum[k]=sum(k,j,i),dp[k]=max(0,dp[k-1]+tmpsum[k]);
				int M=*max_element(tmpsum+1,tmpsum+n+1);
				if(M<0)//all are negative
					best=max(best,M);
				else
					best=max(best,*max_element(dp+1,dp+n+1));
			}
		}
		cout<<best<<'\n';
    }
}
