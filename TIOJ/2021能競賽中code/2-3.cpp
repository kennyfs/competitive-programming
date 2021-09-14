#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5+10;
int n,k,dp[3][N][2],fdp[N][2],last[N][2],mi[2];
string s[3];
char ans[N];
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>k;
    for(int i=0;i<k;++i)cin>>s[i],s[i]=' '+s[i];
    for(int j=1;j<=n;++j){
        //0 0
        mi[0]=mi[1]=1e9;
        for(int i=0;i<k;++i)mi[0]=min(mi[0],dp[i][j-1][0]+(s[i][j]=='1'));
        //1 0
        for(int i=0;i<k;++i)mi[1]=min(mi[1],dp[i][j-1][1]+(s[i][j]=='1'));
        if(mi[0]>mi[1]){
            fdp[j][0]=mi[0],last[j][0]=0;
            for(int i=0;i<k;++i)dp[i][j][0]=dp[i][j-1][0]+(s[i][j]=='1');
        }else{
            fdp[j][0]=mi[1],last[j][0]=1;
            for(int i=0;i<k;++i)dp[i][j][0]=dp[i][j-1][1]+(s[i][j]=='1');
        }

        //0 1
        mi[0]=mi[1]=1e9;
        for(int i=0;i<k;++i)mi[0]=min(mi[0],dp[i][j-1][0]+(s[i][j]=='0'));
        //1 1
        for(int i=0;i<k;++i)mi[1]=min(mi[1],dp[i][j-1][1]+(s[i][j]=='0'));
        if(mi[0]>mi[1]){
            fdp[j][1]=mi[0],last[j][1]=0;
            for(int i=0;i<k;++i)dp[i][j][1]=dp[i][j-1][0]+(s[i][j]=='0');
        }else{
            fdp[j][1]=mi[1],last[j][1]=1;
            for(int i=0;i<k;++i)dp[i][j][1]=dp[i][j-1][1]+(s[i][j]=='0');
        }
       // cout<<fdp[j][0]<<' '<<last[j][0]<<' '<<fdp[j][1]<<' '<<last[j][1]<<'\n';
    }
    int cur;
    if(fdp[n][0]>fdp[n][1])cur=0;
    else cur=1;
    ans[n]=cur+'0';
    for(int i=n;i>=2;--i){
        ans[i-1]=last[i][cur]+'0';
        cur=last[i][cur];
    }
    for(int i=1;i<=n;++i)cout<<ans[i];
}
