#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n;
string a,b;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	while(n--){
		cin>>a>>b;
		bool ans;
		if(a.size()>b.size())ans=0;
		else if(a.size()<b.size())ans=1;
		else{
			bool flag=0;
			for(size_t i=0;i<a.size();++i){
				if(a[i]>b[i]){ans=0;flag=1;break;}
				if(a[i]<b[i]){ans=1;flag=1;break;}
			}
			if(!flag)ans=1;
		}
		cout<<ans<<'\n';
	}
}
