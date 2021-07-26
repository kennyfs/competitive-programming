#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	Hirasawa_Yui_My_Wife
	int t;
	cin>>t;
	while(t--){
		string s,t;
		cin>>s>>t;
		int l=s.size(),n=t.size();
		if(n>l){cout<<"No\n";continue;}
		int start=0;
		if((l-n)%2)start=1;
		int j=0;//confirmed index in t
		bool flag=0;
		for(int i=start;i<l;++i){
			if(s[i]==t[j])j++;
			else{
				if(j==n){flag=1;break;}
				++i;
				continue;//skip two words in s
			}
			if(j==n){flag=1;break;}
		}
		if(flag)cout<<"yes\n";
		else cout<<"nO\n";
	}
}
