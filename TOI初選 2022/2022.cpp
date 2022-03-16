#include <iostream>
#include <vector>
#define ll long long
#define pb push_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=10+5;
int n0,n2;
int main(){
    Hirasawa_Yui_My_Wife
    cin>>n0>>n2;
    if(n0+n2>80)return 1;
    bool found=0,ok=0;
    ll a,b;
    for(ll i=0;i<(1ll<<(n0+n2));++i){
        int chi=0,ooh=0;
        for(int d=0;d<n0+n2;++d){
            if(i>>d&1){
                if(d&1)chi++;
                else ooh++;
            }
        }
        if(abs(chi-ooh)%11!=0)continue;
        if(chi+ooh!=n2)continue;
        if(found){b=i;ok=1;break;}
        found=1;
    }
    if(!ok){cout<<"-1";return 0;}
    found=0;
    for(ll i=(1ll<<(n0+n2))-1;i>=0;--i){
        int chi=0,ooh=0;
        for(int d=0;d<n0+n2;++d){
            if(i>>d&1){
                if(d&1)chi++;
                else ooh++;
            }
        }
        if(abs(chi-ooh)%11!=0)continue;
        if(chi+ooh!=n2)continue;
        if(found)a=i;
        found=1;
    }
    for(int d=n0+n2-1;d>=0;--d){
        if((a>>d)&1)cout<<'2';
        else cout<<'0';
    }
    cout<<'\n';
    for(int d=n0+n2-1;d>=0;--d){
        if((b>>d)&1)cout<<'2';
        else cout<<'0';
    }
}
