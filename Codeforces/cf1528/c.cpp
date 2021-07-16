#include <iostream>
#include <vector>
#include <utility>
#include <set>
#define pii pair<int,int>
#define ll long long
#define pb emplace_back
using namespace std;
inline int read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}
int const N=3e5+120;
int t,n;
vector<int> son1[N],son2[N];
int now=0,l[N],r[N];

set<pii> st;
int ans,ma;
void dfs2(int cur){
	l[cur]=now++;
	for(int i:son2[cur]){
		dfs2(i);
	}
	r[cur]=now++;
}
inline bool cross(int a,int b){
	if(l[a]<l[b]&&r[b]<r[a])return 1;
	if(l[b]<l[a]&&r[a]<r[b])return 1;
	return 0;
}
void add(int cur){
	if(st.empty()){
		++ma;
		st.insert({l[cur],cur});
		return;
	}
	auto it=st.upper_bound({l[cur],0});
	if(it==st.begin()){
		int right=it->second;
		if(!cross(cur,right))++ma;
	}else if(it==st.end()){
		int left=prev(it)->second;
		if(!cross(cur,left))++ma;
	}else{
		auto pit=prev(it);
		int right=it->second,left=pit->second;
		bool rc=cross(right,cur),lc=cross(left,cur),lr=cross(left,right);
		if((!lc&&!rc)||(lc&&!rc&&lr))
			++ma;
	}
	st.insert({l[cur],cur});
}
void dfs1(int cur){
	int tmp=ma;
	add(cur);
	ans=max(ans,ma);
	for(int i:son1[cur])dfs1(i);
	st.erase({l[cur],cur});
	ma=tmp;
}
int main(){
	t=read();
	while(t--){
		n=read();
		int v;
		for(int i=1;i<=n;++i){
			son1[i].clear();
			son2[i].clear();
		}
		for(int i=2;i<=n;++i)v=read(),son1[v].pb(i);
		for(int i=2;i<=n;++i)v=read(),son2[v].pb(i);
		now=0;
		dfs2(1);
		ans=ma=0;
		dfs1(1);
		cout<<ans<<'\n';
	}
}
