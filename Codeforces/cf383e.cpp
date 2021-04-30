#include <iostream>
#include <bitset>
using namespace std;
const int N=10005,NUM=16777216,lgNUM=24;
int n,mypow[30];
short dp[NUM][2];
string s;
void build(){
	mypow[0]=1;
	for(int i=1;i<30;++i)
		mypow[i]=2*mypow[i-1];
}
bool get(int i,int th){//th 0 start from the end
	return (i/mypow[th])%2;
}
int mi(int i,int th){//i minus 2^th
	//get(i,th) MUST be 1
	return i-mypow[th];
}
int main(){
	build();
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s;
		char sa=s[0],sb=s[1],sc=s[2];
		
		dp[mypow[sa-'a']][0]++;
		
		if(sb!=sa)
			dp[mypow[sb-'a']][0]++,
			dp[mypow[sb-'a']+mypow[sa-'a']][0]--;
		if(sc!=sb&&sc!=sa){
			dp[mypow[sc-'a']][0]++,
			dp[mypow[sc-'a']+mypow[sa-'a']][0]--;
			if(sa!=sb)
				dp[mypow[sc-'a']+mypow[sb-'a']][0]--;
		}
	}
	int a=0,b=1;
	for(int j=1;j<=lgNUM;++j){//last j bits can be different
		swap(a,b);
		for(int i=0;i<NUM;++i){
			dp[i][a]=dp[i][b];
			if(get(i,j-1))
				dp[i][a]+=dp[mi(i,j-1)][b];
		}
	}/*
	int q;
	cin>>q;
	while(q--){
		cin>>s;
		int ind=0;
		for(int j=0;j<3;++j)
			if(!get(ind,s[j]-'a'))
				ind+=mypow[s[j]-'a'];
		cout<<bitset<24>(ind)<<endl;
		cout<<dp[ind][a]<<endl;
	}*/
	int ans=0;
	for(int i=1;i<NUM;++i){
		ans^=dp[i][a]*dp[i][a];
	}
	cout<<ans<<'\n';
}
