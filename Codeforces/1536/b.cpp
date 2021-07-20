#include <iostream>
using namespace std;
int t,n;
string s;
void add(string& str){
	bool fin=0;
	for(int a=str.length()-1;a>=0&&(!fin);--a){
		if(str[a]+1>'z'){
			str[a]='a';
		}else{
			str[a]++;
			fin=1;
		}
	}
	if(!fin)str="a"+str;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>s;
		string ans="a";
		for(;s.find(ans)!=string::npos;add(ans));
		cout<<ans<<'\n';
	}
}
