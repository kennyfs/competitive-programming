#include <iostream>
#include <map>
#define int long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int t,n,a;
main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		map<int,int> sum;
		for(int i=0;i<n;++i){
			cin>>a;
			if(sum.count(a)){
				ans+=(n-i)*sum[a];
				sum[a]+=i+1;
			}else{
				sum[a]=i+1;
			}
		}
		cout<<ans<<'\n';
	}
}
