#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define pb emplace_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=4e4+10;
int n,m,c[N];

int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		vector<int> G[n+5];
		int jizz,jizzzz;
		while(m--){
			cin>>jizz>>jizzzz;
			G[jizz].pb(jizzzz);
			G[jizzzz].pb(jizz);
		}
		memset(c,0,sizeof(c));
		queue<int> q;
		bool flag=0;
		for(int i=1;i<=n;++i){
			if(c[i]!=0)continue;
			q.push(i);
			c[i]=1;
			while(!q.empty()){
				int cur=q.front();q.pop();
				for(int nxt:G[cur]){
					if(c[nxt]==0){
						c[nxt]=-c[cur];
						q.push(nxt);
					}else{
						if(c[nxt]==c[cur]){flag=1;break;}
					}
				}
				if(flag)break;
			}
			if(flag)break;
		}
		puts(flag?"No":"Yes");
	}
}
//bfs
