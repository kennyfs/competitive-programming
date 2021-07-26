#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
int t,n;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		cin>>n;
		ll sum=0,tmp;
		for(int i=0;i<n;++i)cin>>tmp,sum+=tmp;
		ll left=sum%n;
		cout<<(n-left)*left<<'\n';
	}
}
