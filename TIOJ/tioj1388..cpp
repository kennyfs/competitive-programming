#include <iostream>
#include <vector>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N=120;
int n;
ll dp[N][N];//dp[i][j] stands for max in [i,j]
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n){
		fill(&dp[0][0],&dp[105][105],0);
		for(int i=0;i<n;++i)cin>>dp[i][i];
		for(int len=1;len<n;++len){
			for(int st=0;st+len<n;++st){//st to st+len
				for(int k=st;k<st+len;++k){//combine st~k and k+1~st+len
					dp[st][st+len]=max(dp[st][st+len],(len%2)?dp[st][k]+dp[k+1][st+len]:dp[st][k]*dp[k+1][st+len]);
				}
				//cout<<"dp:"<<st<<','<<st+len<<','<<dp[st][st+len]<<'\n';
			}
		}
		cout<<dp[0][n-1]<<'\n';
	}
}
