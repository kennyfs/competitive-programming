#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define pb emplace_back
#define pii pair<int,int>
#define F first
#define S second
#define INF 80000000
using namespace std;
const int N=1e3+10;
int n,m;
char map[N][N];
int mdis[N][N],pdis[N][N],mv[N][N],sx,sy;
pii last[N][N],M[N*N];
int nxt[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void mbfs(){//monster bfs, set mdis
	queue<pii> Q;
	for(auto [x,y]:M){
		mdis[x][y]=0;
		Q.push({x,y});
	}
	while(!Q.empty()){
		pii cur=Q.front();Q.pop();
		for(int i=0;i<4;++i){
			int tx=cur.F+nxt[i][0],ty=cur.S+nxt[i][1];
			if(tx>n||ty>m||tx<=0||ty<=0)continue;
			if(map[tx][ty]=='#')continue;
			if(mdis[cur.F][cur.S]+1>=mdis[tx][ty])continue;
			mdis[tx][ty]=mdis[cur.F][cur.S]+1;
			Q.push({tx,ty});
		}
	}
}
string d2t="UDLR";
void output(int x,int y){
	vector<char> ans;
	while(x!=sx||y!=sy){
		ans.pb(d2t[mv[x][y]]);
		int tx=last[x][y].F,ty=last[x][y].S;
		x=tx,y=ty;
	}
	cout<<"YES\n";
	cout<<ans.size()<<'\n';
	reverse(ans.begin(),ans.end());
	for(char c:ans)cout<<c;
	exit(0);
}
void pbfs(int x,int y){
	queue<pii> Q;
	pdis[x][y]=0;
	Q.push({x,y});
	while(!Q.empty()){
		pii cur=Q.front();Q.pop();
		for(int i=0;i<4;++i){
			int tx=cur.F+nxt[i][0],ty=cur.S+nxt[i][1];
			if(tx>n||ty>m||tx<=0||ty<=0)continue;
			if(map[tx][ty]=='#')continue;
			if(pdis[cur.F][cur.S]+1>=pdis[tx][ty])continue;
			pdis[tx][ty]=pdis[cur.F][cur.S]+1;
			if(pdis[tx][ty]>=mdis[tx][ty])continue;
			mv[tx][ty]=i;
			last[tx][ty]={cur.F,cur.S};
			if(tx==n||ty==m||tx==1||ty==1)output(tx,ty);
			Q.push({tx,ty});
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>map[i][j],mdis[i][j]=pdis[i][j]=INF;
	//do monster first
	for(int i=1,stk=0;i<=n;++i){
		for(int j=1;j<=m;++j){
			switch(map[i][j]){
				case 'M':
					M[stk++]={i,j};
					break;
				case 'A':
					sx=i,sy=j;
					break;
			}
		}
	}
	if(sx==1||sx==n||sy==1||sy==m)cout<<"YES\n0",exit(0);
	mbfs();
	pbfs(sx,sy);
	cout<<"NO";
}
