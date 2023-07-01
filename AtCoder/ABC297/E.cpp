#include <bits/stdc++.h>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int N=15;
int n,k,a[N];
priority_queue<int, vector<int>, greater<int>> pq;
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>k;
	while(!pq.empty())pq.pop();
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pq.push(a[i]);
	}
	int smallest,last;
	for(int i=1;i<=k;){
		smallest=pq.top();pq.pop();
		if(smallest==last)continue;
		last=smallest;
		for(int j=1;j<=n;++j){
			pq.push(a[j]+smallest);
		}
		++i;
	}
	cout<<smallest<<'\n';
}
