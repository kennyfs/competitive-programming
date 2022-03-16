#include <iostream>
#include <utility>
#include <map>
#define pii pair<int,int>
#define F first
#define S second
#define wiwiho 25
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e4+10,inf=8e7*wiwiho;
int n,l,r;
string s;
int a[77]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,3,4,5,0,6,7,8};
int dp[N][9][9];
int main(){
    cin>>n>>s;
    fill(&dp[0][0][0],&dp[N-1][8][8]+1,inf);
    dp[0][3][6]=0;
    for(int i=1;i<=n;++i){
        int ind=a[s[i-1]];
        for(int l=0;l<9;++l){
            for(int r=0;r<9;++r){
                if(!(l==ind||r==ind))continue;
                for(int ll=0;ll<9;++ll){
                    dp[i][l][r]=min(dp[i][l][r],dp[i-1][ll][r]+abs(ll-l));
                }
                for(int rr=0;rr<9;++rr){
                    dp[i][l][r]=min(dp[i][l][r],dp[i-1][l][rr]+abs(rr-r));
                }
            }
        }
    }
    int ans=inf;
    char ind=a[s[n-1]];
    for(int l=0;l<9;++l){
        for(int r=0;r<9;++r){
            if(!(l==ind||r==ind))continue;
            ans=min(ans,dp[n][l][r]);
        }
    }
    cout<<ans;
}
