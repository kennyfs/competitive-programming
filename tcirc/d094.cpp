#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int const N=1e6+10;
int n,p,l,r,nxt[N];
bool vis[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>p>>l>>r;
	for(int i=0;i<n;++i)cin>>nxt[i];
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	queue<pii> que;
	que.push({0,0});
	int ans=-1;
	while(!que.empty()){
		pii cur=que.front();
		if(cur.F==p){ans=cur.S;break;}
		if(cur.F+r<n&&0<=nxt[cur.F+r]&&nxt[cur.F+r]<n&&!vis[cur.F+r]){
			vis[nxt[cur.F+r]]=vis[cur.F+r]=1;
			que.push({nxt[cur.F+r],cur.S+1});
		}
		if(0<=cur.F-l&&0<=nxt[cur.F-l]&&nxt[cur.F-l]<n&&!vis[cur.F-l]){
			vis[nxt[cur.F-l]]=vis[cur.F-l]=1;
			que.push({nxt[cur.F-l],cur.S+1});
		}
		que.pop();
	}
	cout<<ans<<'\n';
}
//bfs最短路徑
