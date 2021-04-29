#include <iostream>
using namespace std;
const int N=10005,NUM=16777216+3;
int n,mypow[24];
int dp[NUM][2];
string s;
void build(){
	mypow[0]=1;
	for(int i=1;i<24;++i)
		mypow[i]=2*mypow[i-1];
}
int get(int i,int th){//th 0 start from the end
	return (i/mypow[th])%2;
}
int main(){
	cin>>n;
	for(int i=0;i<=n;++i){
		cin>>s;
		int ind=0;
		for(int j=0;j<3;++j)
			if(get(ind,s[))//continue coding here
			ind+=pow[s[j]-'a'+1];
	}
	int a=1,b=0;
	for(int i=0
}