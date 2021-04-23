#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	Hirasawa_Yui_My_Wife
	short p,q;
	cin>>p>>q;
	if(p<q)swap(p,q);//p>=q
	if(p%q)cout<<"N\n";
	else cout<<"Y\n";
	return 0;
}
