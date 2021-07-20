#include <iostream>
#define ll long long
using namespace std;
int main(){
	ll dp[2][(1<<14)];
	int n,m;
	while(cin>>n>>m&&n&&m){
		if(n<m)swap(n,m);
		int a=1,b=0;
		//dp[s]代表現在狀態為s的方法數，s的狀態是反著寫的
		fill(dp[0],dp[0]+(1<<14),0);
		dp[0][(1<<m)-1]=1;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				swap(a,b);//always a to b
				fill(dp[b],dp[b]+(1<<14),0);
				for(int s=0;s<(1<<m);++s){
					if(dp[a][s]){
						dp[b][s^(1<<j)]+=dp[a][s];
						if(s>>j&1&&j!=0&&!((s>>(j-1))&1))dp[b][s^(1<<(j-1))]+=dp[a][s];
					}
				}
			}
		}
		cout<<dp[b][(1<<m)-1]<<'\n';
	}
}
