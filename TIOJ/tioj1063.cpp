#include <iostream>
#include <stack>
#define Hiarasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define INF 80000000
int data[201][201],l[210],r[210];
int main(){
	Hiarasawa_Yui_My_Wife
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>data[i][j];
	int ans=-INF;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			if(data[i][j])
				data[i][j]=data[i-1][j]+1;
		stack<int> stk;
		data[i][0]=-INF;
		stk.push(0);
		for(int j=1;j<=m;++j){
			while(data[i][j]<=data[i][stk.top()])
				r[stk.top()]=j,stk.pop();
			l[j]=stk.top();
			stk.push(j);
		}
		while(stk.size()){
			r[stk.top()]=m+1;
			stk.pop();
		}
		for(int j=1;j<=m;++j)
			ans=max(ans,data[i][j]*(r[j]-l[j]-1));
	}
	cout<<ans<<'\n';
}
