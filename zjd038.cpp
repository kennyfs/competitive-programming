#include <iostream>
using namespace std;
#define int long long
int dp[51];
main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	dp[0]=dp[1]=1;
	for(int i=2;i<=50;++i){
		dp[i]=dp[i-1]+dp[i-2];
	}
	int q;
	while(cin>>q&&q){
		cout<<dp[q]<<'\n';
	}
}
