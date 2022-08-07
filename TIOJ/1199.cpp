#include <iostream>
#include <cmath>
using namespace std;
int mypow(int a,int b,int mod){
    int ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int main(){
    int ans,n,y;
    while(cin>>ans>>n>>y){
        if(ans==0&&n==0&&y==0)break;
        if(n==0){
            if(ans==1||(y==1&&&ans==0))cout<<y-1<<'\n';
            else cout<<"0\n";
        }else{
            int cnt=0;
            for(int x=0;x<y;++x){
                if(mypow(x,n,y)==ans)++cnt;
            }
            cout<<cnt<<'\n';
        }
    }
}