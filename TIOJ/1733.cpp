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
			up[i][0]=0;
            cin>>g[i][1];up[i][1]=g[i][1];
            for(int j=2;j<=m;++j){
                cin>>g[i][j];
                up[i][j]=up[i][j-1]+g[i][j];
            }
        }
        int best=-2147483647,toupdate;
        for(int i=1;i<=m;++i){
			for(int j=i;j<=m;++j){//[i,j]
				tmpsum[1]=sum(1,i,j);
				dp[1]=max(0,tmpsum[1]);
				for(int k=2;k<=n;++k)tmpsum[k]=sum(k,i,j),dp[k]=max(0,dp[k-1]+tmpsum[k]);
				int M=*max_element(tmpsum+1,tmpsum+n+1);
				if(M<0)//all are negative
					toupdate=M;
				else
					toupdate=*max_element(dp+1,dp+n+1);
				best=max(best,toupdate);
			}
		}
		cout<<best<<'\n';
    }
}
