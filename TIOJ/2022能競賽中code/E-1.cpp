#include <iostream>
using namespace std;
#define int long long
#define wiwiho 5208e7
const int N=2e5+520,inf=8e7*wiwiho,M=1e9+7;
int n,a[N];
int mypow(int a,int b){
    int x=1;
    while(b){
        if(b&1)x=x*a%M;
        a=a*a%M;
        b>>=1;
    }
    return x;
}
signed main(){
    cin>>n;
    cout<<mypow(2,n-1);
}
