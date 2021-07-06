#include <iostream>
using namespace std;
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	Hirasawa_Yui_My_Wife
	int a,b;
	cin>>a>>b;
	for(int i=1;i<a;++i)cout<<i<<' ';
	for(int i=1;i<b;++i)cout<<-i<<' ';
	cout<<1000000-a*(a-1)/2<<' '<<b*(b-1)/2-1000000<<'\n';
}
