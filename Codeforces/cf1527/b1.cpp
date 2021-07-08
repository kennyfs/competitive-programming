#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	Hirasawa_Yui_My_Wife
	int t,n;cin>>t;
	char tmp;
	int a;
	while(t--){
		a=0;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>tmp;
			if(tmp=='0')++a;
		}
		if(a==0){cout<<"DRAW\n";continue;}
		if(a==1){cout<<"BOB\n";continue;}
		if(a&1){
			cout<<"ALICE\n";
		}else{
			cout<<"BOB\n";
		}
	}
}
