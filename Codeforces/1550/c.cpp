#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=2e5+120;
int t,n,a[N];
bool ok(int b,int c,int d){//b<c<d, they are indexes
	return a[c]>max(a[b],a[d])||a[c]<min(a[b],a[d]);
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		int ans=2*n-1;
		//length of 3
		for(int i=1;i+2<=n;++i){
			if(ok(i,i+1,i+2))++ans;
		}
		//length of 4
		for(int i=1;i+3<=n;++i){
			if(ok(i,i+1,i+2)&&ok(i,i+1,i+3)&&ok(i,i+2,i+3)&&ok(i+1,i+2,i+3))++ans;
		}
		cout<<ans<<'\n';
	}
}
