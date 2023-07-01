#include <bits/stdc++.h>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
int a,b;
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>a>>b;
	int ans=0;
	while(a!=b){
		if(a>b){
			ans+=a/b;
			a-=b*(a/b);
		}else{
			ans+=b/a;
			b-=a*(b/a);
		}
		if(a*b==0){--ans;break;}
	}
	cout<<ans<<'\n';
}
