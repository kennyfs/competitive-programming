#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
using namespace std;
int const MAXN=260;
int x,y;
bool map[MAXN][MAXN],vis[MAXN][MAXN];
int N,E,W,S,sz;
int nex[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool dfs(int tx,int ty,bool f){
	if(tx>=x||tx<0||ty>=y||ty<0)return 0;
	if(vis[tx][ty])return 0;
	if(!map[tx][ty])return 0;
	vis[tx][ty]=1;
	if(f){
		N=tx;S=tx;
		E=ty;W=ty;
		sz=0;
	}else{
		N=min(N,tx);W=min(W,ty);
		S=max(S,tx);E=max(E,ty);
	}
	++sz;
	for(int i=0;i<4;++i)
		dfs(tx+nex[i][0],ty+nex[i][1],0);
	return 1;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>x>>y;
	for(int i=0;i<x;++i)for(int j=0;j<y;++j)cin>>map[i][j];
	for(int i=0;i<x;++i)
		for(int j=0;j<y;++j)
			if(dfs(i,j,1))
				cout<<W<<' '<<N<<' '<<E<<' '<<S<<' '<<sz<<'\n';//W N E S sz
		
}
