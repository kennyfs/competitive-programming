#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int p[31];
int main(){
	Hirasawa_Yui_My_Wife
	p[0]=1;
	for(int i=1;i<31;++i)p[i]=p[i-1]*2;
	int t,tmp;
	cin>>t;
	while(t--){
		int i;
		cin>>tmp;
		for(i=0;p[i]<=tmp;++i);
		cout<<p[i-1]-1<<'\n';
	}
}
