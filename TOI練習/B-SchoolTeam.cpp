#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define wiwiho 25;
using namespace std;
const int N=2e3+10;
const int INF=8e7*wiwiho;
int n,m;
int dp[N][N],a[2*N][2];
int qdp(int i,int j){
    if(i==0&&j==0)return 0;
    if(dp[i][j])return dp[i][j];
    if(i>n||j>m||i<0||j<0)return INF;
    dp[i][j]=INF;
    if(i)dp[i][j]=min(dp[i][j],qdp(i-1,j)+a[i+j][0]);
    if(j)dp[i][j]=min(dp[i][j],qdp(i,j-1)+a[i+j][1]);
    return dp[i][j];
}
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>m;
    for(int i=1;i<=n+m;++i){
        cin>>a[i][0]>>a[i][1];
    }
    cout<<qdp(n,m);
}
