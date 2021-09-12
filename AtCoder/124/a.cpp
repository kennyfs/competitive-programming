#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
int const N=1000+10,mod=998244353;
int n,kk;
int poss[N];
bool vis[N];
int main(){
	cin>>n>>kk;
	char c;int k;
	fill(poss,poss+N,kk);
	memset(vis,0,N);
	for(int i=0;i<kk;++i){
		cin>>c>>k;
		if(c=='L'){
			for(int j=1;j<=k;++j)--poss[j];
		}else{
			for(int j=n;j>=k;--j)--poss[j];
		}
		vis[k]=1;
	}
	ll ans=1;
	for(int i=1;i<=n;++i)if(!vis[i])ans=(ans*poss[i])%mod;
	cout<<ans<<'\n';
}

