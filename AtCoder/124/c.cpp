#include <iostream>
#include <cstring>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=2e5+10;
int n,m,a[N],cl[N],cr[N],li=0,ri=0,ans=0;
bool vis[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=0;i<n+m;++i)cin>>a[i];
	memset(vis,0,N);
	for(int i=0;i<n+m;++i){
		if(vis[i])continue;
		bool l=0,r=0;
		int cur=i,len=0;
		while(!vis[cur]){
			vis[cur]=1;
			++len;
			if(cur<n)l=1;
			else r=1;
			cur=a[cur]-1;
		}
		if(len==1)continue;
		if(l&&r)ans+=len-1;
		else if(l)cl[li++]=len;
		else cr[ri++]=len;
	}
	for(int i=0;i<li;++i)ans+=cl[i];
	for(int i=0;i<ri;++i)ans+=cr[i];
	ans+=abs(li-ri);
	cout<<ans<<'\n';
}
