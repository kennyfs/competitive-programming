#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n;
int a[1000010];
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n){
		for(int i=0;i<n;++i)cin>>a[i];
		sort(a,a+n);
		int m1,m2;
		m1=a[n/2];m2=a[(n-1)/2];
		int same=0;
		for(int i=0;i<n;++i)if(a[i]==m1||a[i]==m2)++same;
		cout<<m2<<' '<<same<<' '<<m1-m2+1<<'\n';
	}
}
