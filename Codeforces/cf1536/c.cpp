#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int t,n;
vector<int> dp(500010,0);
string s;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		cin>>n>>s;
		int a=0,b=0;
		vector<map<int,int> > last(n+5);
		for(int i=0;i<n;++i){
			if(s[i]=='D')
				++a;
			else
				++b;
			int g=__gcd(a,b);
			int copya=a,copyb=b;
			a/=g;b/=g;
			if(last[a].count(b)){
				dp[i]=dp[last[a][b]]+1;
			}else{
				dp[i]=1;
			}
			last[a][b]=i;
			cout<<dp[i]<<' ';
			a=copya;b=copyb;
		}
		cout<<'\n';
	}
}
