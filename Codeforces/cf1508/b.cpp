#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb emplace_back
using namespace std;
int t,n,ans[100010];
ll k;
ll mypow[64];
int main(){
	Hirasawa_Yui_My_Wife
	mypow[0]=1;
	for(int i=1;i<62;++i){
		mypow[i]=mypow[i-1]*2;
	}
	cin>>t;
	while(t--){
		cin>>n>>k;//2^59<1e18<2^60
		if(n<61&&k>mypow[n-1]){cout<<"-1\n";continue;}
		//so I ensured 2^(n-1) >= k
		//n-1>=log(k)
		k--;
		string k2;
		k2+='0';
		while(k){
			k2+=(k&1)?'1':'0';
			k>>=1;
		}
		reverse(k2.begin(),k2.end());
		int s=k2.size();
		for(int i=1;i<=n;++i)ans[i]=i;
		int last=n-s+1,now;
		for(int i=n-s+1;i<=n;++i){//1-base
			now=i-(n-s+1);
			if(k2[now]=='1')continue;
			reverse(ans+last,ans+i+1);
			last=i+1;
		}
		for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
		cout<<'\n';
	}
}
//https://www.acwing.com/solution/content/46680/
//https://blog.csdn.net/qq_39602052/article/details/115859624
