#include <iostream>
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	Hirasawa_Yui_My_Wife
    ll n,m;
    ll ans;
    while(cin>>n>>m&&n&&m){
		if(n>m)swap(n,m);
        ans=n*(n+1)*(3*m-n+1)/6;//n<=m
        cout<<ans<<'\n';
    }
}
