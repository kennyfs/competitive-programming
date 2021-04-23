#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	Hirasawa_Yui_My_Wife
	string s;
	getline(cin,s);
	int num=1;
	for(int i=0;i<s.size();++i){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			num=s[i]-'0';
			++i;
			while(i<s.size()&&s[i]-'0'>=0&&s[i]-'0'<=9)num*=10,num+=s[i]-'0',++i;
			--i;
		}else{
			for(int j=0;j<num;++j)cout<<s[i];
			num=1;
		}
	}
}
