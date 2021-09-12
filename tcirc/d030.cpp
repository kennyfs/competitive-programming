#include <iostream>
#include <stack>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5+10,INF=8e7*2.5e1;
int n,l;
int c[N],h[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>l;
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int i=1;i<=n;++i)cin>>h[i];
	c[0]=0;
	c[n+1]=l;
	h[0]=h[n+1]=INF;
	stack<int> stk;
	stk.push(0);
	int tot=0,mx=-INF;
	for(int i=1;i<=n;++i){
		while(c[stk.top()]+h[stk.top()]<=c[i]){
			mx=max(mx,h[stk.top()]);
			++tot;
			stk.pop();
		}
		if(c[stk.top()]<=c[i]-h[i]||c[i]+h[i]<=c[i+1]){//tree i fell
			mx=max(mx,h[i]);
			++tot;
		}else{
			stk.push(i);
		}
	}
	while(c[stk.top()]+h[stk.top()]<l){
		mx=max(mx,h[stk.top()]);
		++tot;
		stk.pop();
	}
	cout<<tot<<'\n'<<mx<<'\n';
}
//greedy好題
