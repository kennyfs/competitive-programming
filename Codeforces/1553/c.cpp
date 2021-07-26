#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
short solve(string& s,int pos,short a=0,short b=0){//see what would happen if s[pos]=val, if it's impossible, return 11
	if(pos>=10)return 10;
	//if this player will definitely lose:
	//if this player will definitely win:
	if(pos&1){
		if(b>a+5-pos/2)return pos;
		if(a>b+5-(pos+1)/2)return pos;
	}else{
		if(a>b+5-pos/2)return pos;
		if(b>a+5-(pos+1)/2)return pos;
	}
	if(s[pos]!='?'){
		if(pos&1)
			return solve(s,pos+1,a+(s[pos]=='1'),b);
		return solve(s,pos+1,a,b+(s[pos]=='1'));
	}
	short ans;
	s[pos]='1';
	if(pos&1)
		ans=solve(s,pos+1,a+1,b);
	else
		ans=solve(s,pos+1,a,b+1);
	s[pos]='0';
	ans=min(ans,solve(s,pos+1,a,b));
	s[pos]='?';
	return ans;
}
int main(){
	Hirasawa_Yui_My_Wife
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		cout<<min(solve(s,0),solve(s,0))<<'\n';
	}
}
