#include <iostream>
#include <algorithm>
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=3060;//I want a 3060 QAQ
ll const INF=1ll<<62;
struct reader{
	int arr,time;//arrive time and reading time
	bool operator<(reader o){//other
		return arr==o.arr?time<o.time:arr<o.arr;
	}
	inline int end(){
		return arr+time;
	}
}pro[N],stu[N];
ll dp[N][N][2];
int n,m;
//dp[i][j] means the minimum time that first i pros and first j stus finished the book(redundant stus are deleted)
//dp[i][j][0] means the last reader is student, dp[i][j][1] means that is a pro.
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	//input
	for(int i=1;i<=n;++i)cin>>pro[i].arr>>pro[i].time;
	for(int i=1;i<=m;++i)cin>>stu[i].arr>>stu[i].time;
	//sort by arrive time
	sort(pro+1,pro+n+1);
	sort(stu+1,stu+m+1);
	int k=0;
	//delete redundant students
	for(int i=1;i<=m;++i){//k is always less than i
		while(k&&stu[k].time<=stu[i].time){//stu[k] arrives before stu[i], so if stu[k] need less time, he/she can always complete the book when stu[i] is reading.
			k--;
		}
		stu[++k]=stu[i];
	}
	//there are n pros and k stus now
	for(int i=0;i<=n;++i)for(int j=0;j<=k;++j)dp[i][j][0]=dp[i][j][1]=INF;
	dp[0][0][0]=dp[0][0][1]=0;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=k;++j){
			dp[i][j+1][0]=min(dp[i][j+1][0],
							  min(max(dp[i][j][0],(ll)stu[j+1].end()),
								  max(dp[i][j][1],(ll)stu[j+1].arr)+(ll)stu[j+1].time));
			dp[i+1][j][1]=min(dp[i+1][j][1],
							  max(min(dp[i][j][0],dp[i][j][1]),(ll)pro[i+1].arr)
						  +(ll)pro[i+1].time);
		}
	}
	cout<<min(dp[n][k][0],dp[n][k][1])<<'\n';
}
