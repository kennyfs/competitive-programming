#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int n,T,q,data[1010][2];
vector<pair<int,int> > query[1010];
int ans[1010];
int main(){
	cin>>n>>T;
	for(int i=1;i<=n;++i)cin>>data[i][0];
	cin>>q;
	int t,x,NON;
	for(int j=0;j<q;++j){
		cin>>NON>>t>>x;
		if(NON==1)return 0;
		query[t].push_back({x,j});
	}
	int a=0,b=1;
	for(int t=1;t<=T;++t){
		swap(a,b);
		data[0][a]=max(data[0][b],data[1][b]);
		for(int i=1;i<n;++i)
			data[i][a]=max(data[i-1][b],max(data[i][b],data[i+1][b]));
		data[n][a]=max(data[n][b],data[n-1][b]);
		for(pair<int,int> p:query[t]){
			ans[p.second]=data[p.first][a];
		}
	}
	for(int j=0;j<q;++j)cout<<ans[j]<<'\n';
}
