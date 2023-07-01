#include <bits/stdc++.h>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int N=2e5+156;
int n;
struct de{
	int id,a,b;
} mydata[N];
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=1;i<=n;++i){
		int a1,b1;
		cin>>a1>>b1;
		mydata[i]={i,a1,b1};
	}
	stable_sort(mydata+1,mydata+n+1,[](de f,de s){return f.a*s.b>s.a*f.b;});
	for(int i=1;i<=n;++i){
		cout<<mydata[i].id<<' ';
	}
	cout<<'\n';
}
