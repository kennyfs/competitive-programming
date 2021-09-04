#include <iostream>
#include <cstring>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e2+5;
int t,n,l[N],dp[2][260*N];
inline int abs(int a){
	return a>0?a:-a;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		cin>>n;
		int sum=0,s,a=1,b=0;//a->b
		for(int i=0;i<n;++i)cin>>l[i],sum+=l[i];
		s=(sum>>1)+(sum&1);
		memset(dp,0,sizeof(dp));
		if(l[0]<=s)dp[0][l[0]]=1;
		dp[0][0]=dp[1][0]=1;
		for(int i=1;i<n;++i){
			swap(a,b);
			for(int j=1;j<=s;++j){
				if(j-l[i]>=0)dp[b][j]=max(dp[a][j],dp[a][j-l[i]]);
				else dp[b][j]=dp[a][j];
			}
		}
		int ans=0;
		for(int j=0;j<=s;++j)if(dp[b][j])ans=j;
		cout<<abs(sum-2*ans)<<'\n';
	}
}
