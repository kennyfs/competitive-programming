#include <iostream>
using namespace std;
int n;
char c[15][15];
int a,dp[15][15];
int main(){
	cin>>n;
	fill(&dp[0][0],&dp[0][0]+sizeof(dp)/sizeof(dp[0][0]),-1);
	dp[0][0]=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>c[i][j];
			if(c[i][j]=='A')continue;
			if(c[i][j]=='X'){
				dp[i][j]=-1;
				continue;
			}
			if(i&&dp[i-1][j]!=-1)dp[i][j]=dp[i-1][j];
			if(j&&dp[i][j-1]!=-1)dp[i][j]=max(dp[i][j],dp[i][j-1]);
			if (c[i][j]=='B')break;
			a=c[i][j]-'0';
			if(dp[i][j]>=0)dp[i][j]+=a;
		}
	}
	if(dp[n-1][n-1]==-1)cout<<"X\n";
	else cout<<dp[n-1][n-1]<<'\n';
}
