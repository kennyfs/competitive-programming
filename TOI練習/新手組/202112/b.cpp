#include <iostream>
using namespace std;
int main(){
	int n;
	string s[210];
	cin>>n;
	int ma=0;
	for(int i=0;i<n;++i)cin>>s[i],ma=max(ma,(int)s[i].size());
	for(int i=0;i<ma;++i){
		for(int ind=0;ind<n;++ind){
			if(i>=s[ind].size())continue;
			if('0'<=s[ind][i]&&s[ind][i]<='9')continue;
			cout<<s[ind][i];
		}
	}
}