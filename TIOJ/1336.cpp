#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=100+10;
char s[N][N];
bool vis[N][N];
int w,h;
int direction[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
void dfs(int x,int y,char cur){
	if(x>=h||y>=w||x<0||y<0)return;
	if(s[x][y]!=cur)return;
	if(vis[x][y])return;
	vis[x][y]=1;
	for(auto a:direction){
		dfs(x+a[0],y+a[1],cur);
	}
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>w>>h;
	fill(&vis[0][0],&vis[0][0]+N*N,0);
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>s[i][j];
	int g=0,n=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(!vis[i][j]){
				if(s[i][j]=='G')++g,dfs(i,j,'G');
				if(s[i][j]=='-')++n,dfs(i,j,'-');
			}
		}
	}
	cout<<g<<' '<<n<<'\n';
}
//easy dfs
