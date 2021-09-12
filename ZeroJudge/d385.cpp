#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,a[51];
bool cmp(int a,int b){
	string sa=to_string(a),sb=to_string(b);
	return stoll(sa+sb)>stoll(sb+sa);
}
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n&&n){
		for(int i=0;i<n;++i)cin>>a[i];
		sort(a,a+n,cmp);
		for(int i=0;i<n;++i)cout<<a[i];
		cout<<'\n';
	}
}
//巧妙的運用sort，懶得自己寫的話可以用stoll
