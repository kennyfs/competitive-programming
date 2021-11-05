#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2e3+10,M=1e9+7;
int n;
string s;
int dp[2][N];//dp[i][j]:第i格，左括號比右括號多j個
void madd(int &a,int b){
    a=(a+b)%M;
}
int main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>s;
    if(s[0]==']'){cout<<"0\n";return 0;}
    dp[0][1]=1;
    int a=1,b=0;
    for(int i=1;i<n;++i){
        swap(a,b);//always a->b
        for(int j=0;j<N;++j)dp[b][j]=0;
        for(int j=0;j<=i+1;++j){//任何時候，左括號一定比較多
            if(dp[a][j]){
                switch(s[i]){
                    case '?':
                        if(j)madd(dp[b][j-1],dp[a][j]);
                        madd(dp[b][j+1],dp[a][j]);
                        break;
                    case '[':
                        madd(dp[b][j+1],dp[a][j]);
                        break;
                    case ']':
                        if(j)madd(dp[b][j-1],dp[a][j]);
                        break;
                }
            }
        }
    }
    cout<<dp[b][0];
}
