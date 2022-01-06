#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	Hirasawa_Yui_My_Wife
	string s;
	char ans[310],a;
	cin>>s>>a;
	int ind=0;
	for(int i=0;i<s.size();++i){
		if(s[i]!=a){
			ans[ind++]=s[i];
		}
	}
	for(int i=0;i<ind;++i){
		if(ans[i]!=ans[ind-i-1]){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}