#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int const M=50+10,N=1000+10;
int m,n;
int c[M],w[N];
bool used[N];
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
	cin>>m>>n;
	for(int i=0;i<m;++i){
		cin>>c[i];
		pq.push(c[i]);
	}
	for(int i=0;i<n;++i)cin>>w[i];
	sort(w,w+n,[&](int a,int b){return a>b;});
	int ans=0,ind=0;
	while(!pq.empty()){
		int t=pq.top();
		ind=0;
		pq.pop();
		while(used[ind]||t-w[ind]<0)ind++;
		if(ind==n)continue;
		used[ind]=1;
		cout<<w[ind]<<'\n';
		++ans;
		pq.push(t-w[ind]);
	}
	cout<<ans<<'\n';
}
