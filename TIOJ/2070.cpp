#include <iostream>
#include <cstring>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
using namespace std;
int const INF=1<<29;
int dp[(1<<21)+10];
int t,k,ss,cur;
string s;
vector<int> task[22];
int main(){
	Hirasawa_Yui_My_Wife
	for(int c=0;c<(1<<20);++c){
		task[__builtin_popcount(c)].pb(c);
	}
	cin>>t;
	while(t--){
		cin>>k>>s;ss=s.size();
		memset(dp,0,((1<<k)+100)*sizeof(dp[0]));
		for(int len=0;len<k;++len){
			for(int c:task[len]){
				for(int bk=0;bk<k;++bk){
					if(c&1<<bk)continue;
					cur=dp[c];
					while(cur<ss&&s[cur]!='a'+bk)++cur;
					dp[c^1<<bk]=max(dp[c^1<<bk],cur);
					if(cur==ss)dp[c^1<<bk]=INF;
				}
			}
		}
		if(dp[(1<<k)-1]!=INF)cout<<"Yes\n";
		else cout<<"No\n";
	}
}
//TLE假解，待解決
