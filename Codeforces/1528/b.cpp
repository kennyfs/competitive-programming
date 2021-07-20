#include <iostream>
using namespace std;
int const N=1000010,mod=998244353;
int dp[N];
void add(int& a,int b){
	a+=b;
	if(a>=mod)a-=mod;
}
int main(){
	int n;
	cin>>n;
	fill(dp,dp+n+5,0);
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;j+=i){
			++dp[j];
		}
	}
	int sum=0;
	for(int i=1;i<=n;++i){
		add(dp[i],sum);
		add(sum,dp[i]);
	}
	cout<<dp[n]<<'\n';
}
