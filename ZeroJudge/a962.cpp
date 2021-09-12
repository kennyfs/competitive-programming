#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
int const mod=1e9+9;
int main(){
	Hirasawa_Yui_My_Wife
    ll n;cin>>n;
    ll sum=0;
    ll b;
    for(ll i=1;i*i<n;++i){
        ll upper,down;
        upper=n/i;
        b=down=n/(i+1)+1;
        ll nn=(upper-down+1)%mod;
        ll c=(n%upper+n%down)%mod;
        sum+=(c*nn)%mod*500000005ll%mod;
        sum%=mod;
    }
    for(ll i=2;i<b;++i){
        sum+=n%i;
        sum%=mod;
    }
    cout<<sum<<'\n';
}
//數學，等差數列，模逆元
