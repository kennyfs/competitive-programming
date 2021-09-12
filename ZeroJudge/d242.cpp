#include <iostream>
#include <algorithm>
#include <stack>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=500100;
int tmp;
int a[N],dp[N],v[N];
stack<int> stk;
int main(){
	Hirasawa_Yui_My_Wife
	int i=1,ind=0;
	cin>>a[0];
	v[ind++]=a[0];
	dp[0]=ind;
	while(cin>>a[i]){
		int now=lower_bound(v,v+ind,a[i])-v;
		if(now==ind)v[ind++]=a[i];
		else v[now]=a[i];
		dp[i++]=now+1;
	}
	int ma=0;
	for(int j=0;j<i;++j){
		if(dp[j]>=ma)ma=dp[j],ind=j;
	}
	cout<<ma<<"\n-\n";
	int last=dp[ind]+1;
	while(true){
		while(dp[ind]!=last-1)--ind;
		stk.push(a[ind]);
		--last;
		if(dp[ind]==1)break;
	}
	while(!stk.empty())cout<<stk.top()<<'\n',stk.pop();
}
//裸LIS，輸出解
