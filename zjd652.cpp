#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	Hirasawa_Yui_My_Wife
	int n;cin>>n;
	vector<int> l(n+5);
	for(int i=0;i<n;++i)cin>>l[i];
	vector<vector<int>> dp(n+5,vector<int>(n,8e7));
	dp[n-1][n-1]=0;
	for(int i=0;i<n-1;++i)dp[i][i]=dp[i][i+1]=0;
	for(int len=2;len<n;++len)//len=1 to n-1 //len is actually len-1
		for(int st=0;st+len<n;++st){//list is st to st+len
			for(int k=st+1;k<st+len;++k){
				dp[st][st+len]=min(dp[st][st+len],dp[st][k]+dp[k][st+len]+l[st]*l[k]*l[st+len]);
			}
		}
	cout<<dp[0][n-1]<<'\n';
}
