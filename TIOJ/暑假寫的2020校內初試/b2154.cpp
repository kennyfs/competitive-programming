#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=200010;
int n;
string s[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=0;i<n;++i)cin>>s[i];
	bool flag=1;
	for(char w='a';w<='z';++w){
		flag=1;
		for(int i=0;i<n;++i){
			if(s[i].find(w)==string::npos){flag=0;break;}
		}
		if(flag){
			cout<<w<<'\n';
			return 0;
		}
	}
	cout<<"7122\n";
}
