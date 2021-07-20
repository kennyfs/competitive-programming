#include <iostream>
#include <algorithm>
using namespace std;

int a[110], dp[110];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    int totaln;
    cin>>totaln;
    for(int i=0;i<totaln;i++){
		int n;
		cin>>n;
		for(int j=0;j<n;j++)cin>>a[j];
		for(int j=0;j<n;j++)dp[j]=max(0,dp[j-1]+a[j]);
		int M=*max_element(a,a+n);
		if(M<0){//all are negative
			cout<<M<<'\n';
		}else{
			cout<<*max_element(dp, dp+n)<<'\n';
		}
	}
}
