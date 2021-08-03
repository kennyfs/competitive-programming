#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int t,n,a,b;
string s;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		cin>>s;
		if(b>=0){
			cout<<(a+b)*n<<'\n';continue;
		}
		int stk=0;char last='8';
		for(int i=0;i<n;++i)
			if(s[i]!=last)
				++stk,last=s[i];
		cout<<a*n+(stk/2+1)*b<<'\n';
	}
}
