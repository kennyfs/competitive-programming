#include <iostream>
#define ll long long
using namespace std;
ll n;
ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	if(!b)return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return b*(a/gcd(a,b));
}
int main(){
	cin>>n;
	ll nowlcm=1;
	for(ll i=2;i<=n;++i){
		nowlcm=lcm(nowlcm,i);
	}
	cout<<nowlcm+1<<'\n'; 
}
