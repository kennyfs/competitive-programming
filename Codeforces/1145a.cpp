#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int short
using namespace std;
int const N=16;
int n;
int a[N];
int ans(int l,int r){
	int m=(l+r)>>1;
	if(r-l==2){
		if(a[l]<=a[l+1])return 2;
		return 1;
	}
	int a1=ans(l,m),a2=ans(m,r);
	if(a1+a2==r-l&&a[m-1]<=a[m])return r-l;
	return max(a1,a2);
}
main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	if(n==1){cout<<"1\n";return 0;}
	for(register int i=0;i<n;++i)cin>>a[i];
	cout<<ans(0,n)<<'\n';
}
