#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int p[80];
int main(){
	Hirasawa_Yui_My_Wife
	p[0]=0;
	for(int i=1;i<80;++i)p[i]=p[i-1]+2*i-1;//i^2-(i-1)^2=2*i-1
	int t,s;cin>>t;
	while(t--){
		cin>>s;
		int ans=lower_bound(p,p+80,s)-p;
		cout<<ans<<'\n';
	}
}
