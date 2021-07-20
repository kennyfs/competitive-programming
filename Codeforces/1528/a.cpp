#include <iostream>
#include <vector>
#include <cstdlib>
#define pb emplace_back
#define ll long long
using namespace std;
int const N=100010;
int t,n;
int l[N],r[N];
vector<int> con[N];
ll dpl[N],dpr[N];
inline int read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}
inline int abs(int a){
	return (a>0)?a:-a;
}
void dfs(int cur,int fa){
	dpl[cur]=0;dpr[cur]=0;
	for(int i:con[cur]){
		if(i==fa)continue;
		dfs(i,cur);
		dpl[cur]+=max(dpr[i]+abs(l[cur]-r[i]),dpl[i]+abs(l[cur]-l[i]));
		dpr[cur]+=max(dpr[i]+abs(r[cur]-r[i]),dpl[i]+abs(r[cur]-l[i]));
	}
}
int main(){
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;++i){
			con[i].clear();
			l[i]=read();r[i]=read();
		}
		int u,v;
		for(int i=0;i<n-1;++i){
			u=read();v=read();
			con[v].pb(u);con[u].pb(v);
		}
		dfs(1,0);
		cout<<max(dpl[1],dpr[1])<<'\n';
	}
}
