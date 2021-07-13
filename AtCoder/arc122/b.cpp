#include <iostream>
#include <algorithm>
#include <iomanip>
#define ll long long
#define double long double
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
double const INF=1e18;
int n;
int a[100010];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	double ans=INF;
	ll sum=0;
	for(int i=0;i<n;++i){//let 2x=a[i]
		sum+=a[i];
		double x=(double)a[i]/2;
		double now=x-(double)sum/n-(double)a[i]*(n-i-1)/n;
		ans=min(ans,now);
	}
	ans+=(double)sum/n;
	cout<<std::fixed << std::setprecision(10)<<ans<<'\n';
}
