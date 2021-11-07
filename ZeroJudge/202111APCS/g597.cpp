#include <iostream>
#include <algorithm>
#define int long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2e5+10;
int n,m;
int l[N],pre[N];
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		l[a]+=c;
		l[b+1]-=c;
	}
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]+l[i];
	}
	sort(pre+1,pre+n+1,[&](int a,int b){return a>b;});
	for(int i=1;i<=n;++i)cin>>l[i];
	sort(l+1,l+n+1);
	int ans=0;
	for(int i=1;i<=n;++i)ans+=pre[i]*l[i];
	cout<<ans;
}
