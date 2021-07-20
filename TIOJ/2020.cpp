#include <iostream>
#define Hiarasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,m;
int dp[105][105];
int gdp(int a,int b){
	return (a>=b)?dp[a][b]:dp[b][a];
}
int main(){
	Hiarasawa_Yui_My_Wife
	//base
	for(int i=1;i<=100;++i)dp[1][i]=dp[i][1]=i;
	
	for(int i=1;i<=100;++i){
		for(int j=1;j<=i;++j){
			if(i==j){dp[i][j]=1;continue;}
			dp[i][j]=8e7;
			for(int k=1;k<j;++k)//[1,k] and [k+1,j]
				dp[i][j]=min(dp[i][j],gdp(i,k)+gdp(i,j-k));
			for(int k=1;k<i;++k)//[1,k] and [k+1,i]
				dp[i][j]=min(dp[i][j],gdp(k,j)+gdp(i-k,j));
		}
	}
	cin>>n>>m;
	cout<<gdp(n,m)<<'\n';
}
