#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int const mod=1e9+7;
int n,a[100010];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	int ans=a[0]-0+1;
	for(int i=0;i<n-1;++i)if(a[i]!=a[i+1])ans=(ll)ans*(a[i+1]-a[i]+1)%mod;
	cout<<ans<<'\n';
}
