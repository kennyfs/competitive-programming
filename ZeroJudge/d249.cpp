#include <iostream>
#include <unordered_set>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=10000+10;
int p[N];
int n,m;
unordered_set<int> st[N];
int P(int cur){
	if(p[cur]==cur)return cur;
	st[p[cur]].erase(cur);
	p[cur]=P(p[cur]);
	st[p[cur]].insert(cur);
	return p[cur];
}
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n>>m){
		for(int i=1;i<=n;++i){
			p[i]=i;
			st[i].clear();
		}
		int op,x,y;
		while(m--){
			cin>>op;
			switch(op){
				case 1:
					cin>>x>>y;
					x=P(x);y=P(y);
					if(x!=y){
						p[x]=y;
						st[y].insert(x);
					}
					break;
				case 2:
					cin>>x;
					if(p[x]==x){
						if(st[x].size()==0)continue;
						int fa=*st[x].begin();
						st[x].erase(fa);
						p[fa]=fa;
						for(int i:st[x]){
							p[i]=fa;
							st[fa].insert(i);
						}
						st[x].clear();
					}else{
						int fa=P(x);
						for(int i:st[x]){
							p[i]=fa;
							st[fa].insert(i);
						}
						st[x].clear();
						st[p[x]].erase(x);
						p[x]=x;
					}
					break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)if(p[i]==i)ans++;
		cout<<ans<<'\n';
	}
}
//神奇的並查集dsu
