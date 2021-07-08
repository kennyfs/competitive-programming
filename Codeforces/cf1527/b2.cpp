#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	Hirasawa_Yui_My_Wife
	int t;cin>>t;
	while(t--){
		int n;
		string tmp;
		int a=0,b=0,ans=0;//a:different, b:both 0
		cin>>n>>tmp;
		for(int i=0;i<n/2;++i){
			if(tmp[i]!=tmp[n-1-i])++a;
			else if(tmp[i]=='0')++b;
		}
		if((n&1)&&tmp[n/2]=='0')ans=b?a+1:a-1;
		else ans=b?(a?1:-1):a;
		if(ans==0)cout<<"DRAW\n";
		else if(ans>0)cout<<"ALICE\n";
		else cout<<"BOB\n";
	}
}
