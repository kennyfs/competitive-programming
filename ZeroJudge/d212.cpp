#include <iostream>
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int dp[110];
int main(){
	//Hirasawa_Yui_My_Wife
	dp[0]=dp[1]=1;
	for(int i=2;i<100;++i)dp[i]=dp[i-1]+dp[i-2],cout<<i<<' '<<dp[i]<<'\n';
	int n;
	while(cin>>n)cout<<dp[n]<<'\n';
}
