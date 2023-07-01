#include <bits/stdc++.h>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int N=2e5+156;
int n,a[N],dp[3][8];
string s;
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	cin>>s;
	for(int i=0;i<n;++i){
		switch(s[i]){
			case 'M':
			dp[0][1<<a[i+1]]++;
			break;
			case 'E':
			for(int j=0;j<8;++j){
				dp[1][j|(1<<a[i+1])]+=dp[0][j];
			}
			break;
			case 'X':
			for(int j=0;j<8;++j){
				dp[2][j|(1<<a[i+1])]+=dp[1][j];
			}
			break;
		}
	}
	int ans=0;
	for(int j=0;j<8;++j){
		int a,b,c;
		a=j&4;
		b=j&2;
		c=j&1;
		if(c){//has 0
			if(b){//has 1
				if(a)//has 2 =>3
					ans+=dp[2][j]*3;
				else
					ans+=dp[2][j]*2;
			}else{
				ans+=dp[2][j];
			}
		}
	}
	cout<<ans<<'\n';
}
