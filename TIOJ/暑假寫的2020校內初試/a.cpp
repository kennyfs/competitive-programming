#include <iostream>
#include <iomanip>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
int const N=500010;
int n;
int x[N],y[N];
ll sumx,sumy;
double sumpx,sumpy;
double const pi=3.141592653589793238462643383;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	sumx=sumy=0;
	sumpx=sumpy=0;
	for(int i=0;i<n;++i){
		cin>>x[i]>>y[i];
		sumx+=x[i];
		sumy+=y[i];
		sumpx+=(double)x[i]*x[i];
		sumpy+=(double)y[i]*y[i];
	}
	double ans=0;
	for(int i=0;i<n;++i){
		ans+=(double)x[i]*x[i]*(n-2);
		ans+=(double)y[i]*y[i]*(n-2);
		ans+=sumpx;
		ans+=sumpy;
		ans-=2.0*x[i]*(sumx-x[i]);
		ans-=2.0*y[i]*(sumy-y[i]);
	}
	ans/=4;
	ans*=pi;
	cout<<fixed<<setprecision(10)<<ans<<'\n';
}
