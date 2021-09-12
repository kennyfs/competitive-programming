#include <iostream>
using namespace std;
int n,k,data[1000010],dp[1000010][7],la[1000010][7];
int main(){
	cin>>n>>k;
	for(int i=0;i<7;++i)dp[0][i]=0;
	for(int i=1;i<=n;++i){
		cin>>data[i];
		dp[i][1]=dp[i-1][1]+data[i];
		la[i][1]=n;
	}
	for(int j=2;j<=k;++j){
		for(int i=j;i<=n;++i){
			dp[i][j]=dp[i-1][j-1];
			la[i][j]=i;
			
			if(j<=i-1&&dp[i-1][j]>dp[i][j])
				dp[i][j]=dp[i-1][j],
				la[i][j]=la[i-1][j];
			dp[i][j]+=(j)?-data[i]:data[i];
			cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	}
	int i=n,j=k;
	while(j--){
		i=la[i][j];
		cout<<i<<'\n';
	}
	cout<<dp[n][k]<<'\n';
}
//未寫完，待解決
