#include <bits/stdc++.h>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
signed main(){
	Hirasawa_Yui_My_Wife
	int a,b;
	a=99;
	bool ok=true;
	for(int i=0;i<8;++i){
		cin>>b;
		if(b<a||b>675||b<100||b%25!=0){ok=false;break;}
		a=b;
	}
	if(ok)cout<<"Yes";
	else cout<<"No";
}
