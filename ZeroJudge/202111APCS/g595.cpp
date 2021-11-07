#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e2+10;
int n,a[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int ans=0;
	for(int i=2;i<=n-1;++i)if(a[i]==0)ans+=min(a[i+1],a[i-1]);
	if(a[1]==0)ans+=a[2];
	if(a[n]==0)ans+=a[n-1];
	cout<<ans;
}
