#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e4+10;
int n,m,dpl[N],dpr[N],dp[2][N],l[51][N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>l[i][j];
	for(int i=0;i<m;++i)dp[0][i]=0;
	int a=1,b=0;//a->b
	for(int i=0;i<n;++i){
		swap(a,b);
		dpl[0]=dp[a][0]+l[i][0];
		for(int j=1;j<m;++j)
			dpl[j]=max(dp[a][j],dpl[j-1])+l[i][j];
		dpr[m-1]=dp[a][m-1]+l[i][m-1];
		for(int j=m-2;j>=0;--j)
			dpr[j]=max(dp[a][j],dpr[j+1])+l[i][j];
		for(int j=0;j<m;++j)
			dp[b][j]=max(dpr[j],dpl[j]);
	}
	cout<<*max_element(&dp[b][0],&dp[b][m])<<'\n';
}
