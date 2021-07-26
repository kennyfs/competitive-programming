#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	Hirasawa_Yui_My_Wife
	int q;
	string s,t,s1,s2;
	cin>>q;
	bool flag;
	while(q--){
		cin>>s>>t;
		flag=0;
		for(size_t i=0;i<s.size();++i){
			s1="";
			for(size_t j=i;j<s.size();++j){
				s1+=s[j];
				s2=s1;
				if(s2==t){cout<<"YES\n";flag=1;break;}
				for(int k=j-1;k>=0;--k){
					s2+=s[k];
					if(s2==t){cout<<"YES\n";flag=1;break;}
				}
				if(flag)break;
			}
			if(flag)break;
		}
		if(!flag)cout<<"NO\n";
	}
}
