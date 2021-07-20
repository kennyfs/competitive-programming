#include <iostream>
#include <vector>
#include <utility>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
using namespace std;
int t,n;
int a[110],b[110],mi[110];
vector<pii> ans;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		ans.clear();
		cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		int sum=0;
		for(int i=0;i<n;++i)cin>>b[i],mi[i]=b[i]-a[i],sum+=mi[i];
		if(sum!=0){cout<<"-1\n";continue;}
		int i=0,j=0;//i:index of positive num, j:index of negative num, don't care 0
		while(true){
			while(i<n&&mi[i]<=0)++i;
			while(j<n&&mi[j]>=0)++j;
			if(i==n||j==n)break;
			int times=min(mi[i],-mi[j]);
			for(int m=0;m<times;++m)ans.push_back({j+1,i+1});
			mi[i]-=times;
			mi[j]+=times;
		}
		cout<<ans.size()<<'\n';
		for(pii i:ans){
			cout<<i.first<<' '<<i.second<<'\n';
		}
	}
}
