#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string s;
inline int ab(int a){
	return a>0?a:-a;
}
int now=0,ans=0;
int main(){
	Hirasawa_Yui_My_Wife
	while(getline(cin,s)){
		now=0,ans=0;
		for(register size_t i=0;i<s.size();++i){
			if(s[i]=='y')ans+=ab(now-i),now+=3;
		}
		cout<<ans<<'\n';
	}
}
