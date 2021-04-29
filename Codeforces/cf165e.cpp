#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1000005,NUM=4194304+3,lgNUM=22+1;
int n,mydata[N];
bool dp[NUM][2];//dp[i][j] means i's last j bits can be different
int ans[NUM][2],mypow[lgNUM];
int lowbit(int i){
	return i&(-i);
}
void buildmypow(){
	mypow[0]=1;
	for(int i=1;i<lgNUM;++i){
		mypow[i]=2*mypow[i-1];
	}
}
int get(int i,int th){//th 0 start from the end
	return (i/mypow[th])%2;
}
int mi(int i,int th){//i minus 2^th
	//get(i,th) MUST be 1
	return i-mypow[th];
}
int main(){
	Hirasawa_Yui_My_Wife
	buildmypow();
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>mydata[i];
		dp[mydata[i]][0]=1;
		ans[mydata[i]][0]=mydata[i];
	}
	int a=0,b=1;
	for(int j=1;j<=lgNUM;++j){
		for(int i=0;i<NUM;++i){
			dp[i][b]=dp[i][a];
			ans[i][b]=ans[i][a];
			if(get(i,j-1)&&dp[mi(i,j-1)][a])
				dp[i][b]=1,
				ans[i][b]=ans[mi(i,j-1)][a];
		}
		swap(a,b);
	}
	int num;
	for(int i=1;i<=n;++i){
		num=4194303-mydata[i];
		if(dp[num][a])
			cout<<ans[num][a]<<' ';
		else
			cout<<"-1 ";
	}
	cout<<endl;
}
