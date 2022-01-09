#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N=5e4+10,LEN=110,T=257,M=1410213593;
int n,len[N],hs[N][LEN],allhs[N];
string s[N];
int mypow(int a,int b){
	int x=1;
	while(b){
		if(b&1)x=x*a%M;
		a=a*a%M;
		b>>=1;
	}
	return x;
}
int inv(int a){
	return mypow(a,M-2);
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s[i];len[i]=s[i].size();
		hs[i][0]=s[i][0];
		for(int j=1;j<len[i];++j){
			hs[i][j]=(hs[i][j-1]*T+s[i][j])%M;
		}
		allhs[i]=hs[i][len[i]-1];
	}
	sort(allhs+1,allhs+n+1);
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=len[i];++j){
			if(j>=len[i]-j-1)break;
			//compare [0,j] and [len[i]-j-1,len[i]-1]
			if(hs[i][j]!=((hs[i][len[i]-1]-hs[i][len[i]-j-2]*mypow(T,j+1))%M+M)%M)continue;
			//and look for [j+1,len[i]-j-2]
			int tmp=((hs[i][len[i]-j-2]-hs[i][j]*mypow(T,len[i]-2*j-2)%M)%M+M)%M;
			ans+=upper_bound(allhs+1,allhs+n+1,tmp)-lower_bound(allhs+1,allhs+n+1,tmp);
		}
	}
	cout<<ans;
}
