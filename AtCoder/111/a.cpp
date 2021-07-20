#include <iostream>
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Would
#define you
#define please
using namespace std;
ll n,m;
ll p(ll a,ll b){
	ll x=1;
	while(b){
		if(b&1)x=x*a%(m*m);
		a=a*a%(m*m);
		b/=2;
	}
	return x;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	cout<<(p(10,n)/m)%m<<'\n';
	Would you please return 0;
}
