#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=2000+10;
int n;
int a[N],b[N],c[N],ans[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)cin>>b[i];
	sort(b,b+n);
	int goal,k=0;bool flag;
	for(int i=0;i<n;++i){
		goal=a[0]^b[i];
		for(int i=0;i<n;++i)c[i]=a[i]^goal;//a[i]^c[i]=goal
		sort(c,c+n);
		flag=1;
		for(int i=0;i<n;++i)if(b[i]!=c[i]){flag=0;break;}
		if(flag)ans[k++]=goal;
	}
	sort(ans,ans+k);
	k=unique(ans,ans+k)-ans;
	cout<<k<<'\n';
	for(int i=0;i<k;++i)cout<<ans[i]<<'\n';
}

