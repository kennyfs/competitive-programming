#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int t,n,m;
string tmp;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		cin>>n>>m;
		string ans(m,0);
		for(int i=0;i<2*n-1;++i){
			cin>>tmp;
			for(int j=0;j<m;++j){
				ans[j]^=tmp[j];
			}
		}
		cout<<ans<<'\n';
	}
	cout<<flush;
}
