#include <bits/stdc++.h>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int r[10];
signed main(){
    Hirasawa_Yui_My_Wife
	int mx=0;
	for(int i=1,a;i<=3;++i){
		cin>>a;
		mx=max(mx,++r[a]);
	}
	cout<<mx<<' ';
	for(int i=9;i>=1;--i){
		if(r[i])cout<<i<<' ';
	}
}
