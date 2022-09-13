#include <iostream>
using namespace std;
#define int long long
#define wiwiho 5208e7
const int N=2e5+520,inf=8e7*wiwiho,M=1e9+7;
const int MOD=5205227;
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
int hsh[MOD];
bool go(int st){
    int cur=0;
    for(int i=1;i<=n;++i){
        if(st&1){
            cur=(cur*n+a[i])%MOD;
        }
        st>>=1;
    }
    if(!hsh[cur]){
        hsh[cur]=1;
        return 1;
    }
    return 0;
}
signed main(){
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;++i)cin>>a[i];
    if(n<=15){
        for(int st=0;st<(1<<n);++st){
            if(go(st))ans++;
        }
        cout<<(ans>>1);
    }else{
        cout<<mypow(2,n-1);
    }
}
