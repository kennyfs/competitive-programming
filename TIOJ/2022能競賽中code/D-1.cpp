#include <iostream>
using namespace std;
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define wiwiho 5208e7
const int N=2e5+520,sN=3e3+10,inf=8e7*wiwiho;
int n,k,a[N],dp[sN][sN];
bool ok[N];
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>k;
    if(n>3000)return 0;
    for(int i=1;i<=n;++i){
        char c;
        cin>>c;
        ok[i]=(c=='1');
    }
    for(int i=1;i<=n;++i)cin>>a[i];
    if(n<=3000){
        int ans=0;
        for(int i=1;i<=n;++i){
            if(ok[i]){
                dp[i][0]=a[i];
                ans=max(ans,dp[i][0]);
                for(int j=1;j<=k;++j){
                    dp[i][j]=dp[i-1][j]+a[i];
                    ans=max(ans,dp[i][j]);
                }
            }else{
                dp[i][1]=a[i];
                ans=max(ans,dp[i][1]);
                for(int j=2;j<=k;++j){
                    dp[i][j]=dp[i-1][j-1]+a[i];
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        cout<<ans<<'\n';
    }
}
