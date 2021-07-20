#include <iostream>
#include <algorithm>
using namespace std;
int now,lastdp[110],dp[110];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int layer;cin>>layer;
	for(int x=1;x<=layer;++x){
		for(int y=1;y<=x;++y){
			cin>>now;
			if(y==1){
				dp[1]=lastdp[1]+now;
			}else if(y==x){
				dp[y]=lastdp[y-1]+now;
			}else{
				dp[y]=max(lastdp[y],lastdp[y-1])+now;
			}
		}
		copy(dp,dp+110,lastdp);
	}
	cout<<*max_element(dp+1,dp+layer+1)<<'\n';
}
