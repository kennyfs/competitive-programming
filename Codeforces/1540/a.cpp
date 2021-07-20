#include <iostream>
#include <algorithm>
using namespace std;
int t,n;
int a[100010];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		sort(a,a+n);
		long long ans=a[n-1],sum=0;
		for(int i=0;i<n;++i){
			sum+=a[i];
			ans+=sum-1ll*a[i]*(i+1);
		}
		cout<<ans<<'\n';
	}
}
