#include <iostream>
#include <set>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e6+10,K=25,INF=8e7;
int n,k,dp[N][K],dp2[N][K],a[N],ma[N],ans[N];//max length to left
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	set<int> st;int j=1;
	st.insert(a[1]);
	ma[1]=1;
	for(int i=2;i<=n;++i){
		auto it=st.find(a[i]);
		if(it==st.end()){
			ma[i]=ma[i-1]+1;
		}else{
			do{
				st.erase(a[j++]);
			}while(a[j-1]!=a[i]);
			ma[i]=i-j+1;
		}
		st.insert(a[i]);
	}
	ans[0]=0;
	dp2[1][1]=1;
	for(int i=1;i<=n;++i){
		dp[i][1]=ma[i];
		dp2[i][1]=max(dp[i][1],dp2[i-1][1]);
		for(int j=2;j<=min(i,k);++j){
			dp[i][j]=dp2[i-ma[i]][min(j-1,i-ma[i])]+ma[i];
			dp2[i][j]=dp[i][j];
			if(i-1>j)dp2[i][j]=max(dp2[i][j],dp2[i-1][j]);
		}
	}
	cout<<dp2[n][k]<<'\n';
}
