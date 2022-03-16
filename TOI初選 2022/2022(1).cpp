#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
#define pb push_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=2e5+10;
int n0,n2;
struct A{
    bool digits[N];
    int chi=0,ooh=0;
    A():chi(0),ooh(0){
        memset(digits,0,sizeof(digits));
    }
    void operator--(){
        if(digits[0]){digits[0]=0;ooh--;return;}
        digits[0]=1;ooh++;
        for(int i=1;i<N;++i){
            if(digits[i]){
                digits[i]=0;
                if(i&1)chi--;
                else ooh--;
                return;
            }else{
                digits[i]=1;
                if(i&1)chi++;
                else ooh++;
            }
        }
    }
    void operator++(){
        if(!digits[0]){digits[0]=1;ooh++;return;}
        digits[0]=0;ooh--;
        for(int i=1;i<N;++i){
            if(!digits[i]){
                digits[i]=1;
                if(i&1)chi++;
                else ooh++;
                return;
            }else{
                digits[i]=0;
                if(i&1)chi--;
                else ooh--;
            }
        }
    }
}big,small;
int main(){
    Hirasawa_Yui_My_Wife
    cin>>n0>>n2;
    if(n0==0||n2==0){cout<<"-1";return 0;}
    if(!(n2&1)){
        for(int i=n0;i<n0+n2;++i){
            big.digits[i]=1;
            if(i&1)big.chi++;
            else big.ooh++;
        }
        for(int i=0;i<n2;++i){
            small.digits[i]=1;
            if(i&1)small.chi++;
            else small.ooh++;
        }
    }else{
        {cout<<"-1";return 0;}
    }
    int ind=-1,zero=-1,one=-1;
    for(int i=2;i<N;++i){
        if(big.digits[i]){ind=i;break;}
    }
    for(int i=ind-2;i>=0;i-=2){
        if(!big.digits[i]){zero=i;break;}
    }
    big.digits[zero]=1;
    big.digits[ind]=0;
    for(int i=n0+n2-1;i>=0;--i){
        if(big.digits[i])cout<<'2';
        else cout<<'0';
    }
    cout<<'\n';
    while(abs(small.chi-small.ooh)%11||small.chi+small.ooh!=n2){
        ++small;
    }
    ind=-1;
    for(int i=2;i<N;++i){
        if(!small.digits[i]){ind=i;break;}
    }
    for(int i=ind-2;i>=0;i-=2){
        if(small.digits[i]){one=i;break;}
    }
    small.digits[one]=0;
    small.digits[ind]=1;
    for(int i=n0+n2-1;i>=0;--i){
        if(small.digits[i])cout<<'2';
        else cout<<'0';
    }
    cout<<'\n';
}
