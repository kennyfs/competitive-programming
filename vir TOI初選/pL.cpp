#include <iostream>
#include <map>
using namespace std;
map<string,int> cnt;
string s;
int getelelen(int st){
	if('a'<=s[st+1]&&s[st+1]<='z')return 2;
	return 1;
}
int getnum(int& st){
	int ans=0;
	while('0'<=s[st]&&s[st]<='9'){
		ans*=10;
		ans+=s[st]-'0';
		st++;
	}
	return ans;
}
void count(int l,int r){//[l,r)
	if(l>=r)return;
	int elelen=getelelen(l);
	string ele=s.substr(l,elelen);
	l+=elelen;
	num=1;
	if('0'<=s[l]&&s[l]<='9'){
		num=getnum(l);
	}
	if(mp.find(ele)!=mp.end()){
		mp[ele]+=num;
	}
}
int main(){
	getline(cin,s);
	count(0,s.size());
}