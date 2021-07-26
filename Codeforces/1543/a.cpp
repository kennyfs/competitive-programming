#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
int t;
ll gcd(ll a,ll b){
	return (b)?gcd(b,a%b):a;
}
int main(){
	//Hirasawa_Yui_My_Wife
	cin>>t;
	ll a,b;
	while(t--){
		cin>>a>>b;
		if(a<b)swap(a,b);
		if(a==b){cout<<"0 0\n";continue;}
		ll c=a-b;
		cout<<c<<' '<<min(a%c,c-a%c)<<'\n';//a%c,b%c should be 0
	}
}
