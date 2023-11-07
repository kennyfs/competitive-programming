#include <stdio.h>
#define N 56
char grid[N][N];
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n;
int adj(int x,int y){
	int ans=0;
	for(int i=0;i<4;++i){
		int tx=x+d[i][0],ty=y+d[i][1];
		if(tx>=n||tx<0||ty>=n||ty<0)continue;
		if(grid[tx][ty]!='0')ans++;
	}
	return ans;
}
void dfs(int x,int y,int fx,int fy){
	printf("%c",grid[x][y]);
	for(int i=0;i<4;++i){
		int tx=x+d[i][0],ty=y+d[i][1];
		if(tx>=n||tx<0||ty>=n||ty<0||(tx==fx&&ty==fy)||grid[tx][ty]=='0')continue;
		dfs(tx,ty,x,y);
	}
}
int main(){
	scanf("%d",&n);
	for(int x=0;x<n;++x){
		for(int y=0;y<n;++y){
			do{
				scanf("%c",&grid[x][y]);
			}while(grid[x][y]=='\n');
		}
	}
	grid[n][n]=127;
	int hx=n,hy=n;
	for(int x=0;x<n;++x){
		for(int y=0;y<n;++y){
			if(grid[x][y]!='0'&&adj(x,y)==1&&(grid[x][y]<grid[hx][hy]||(grid[x][y]==grid[hx][hy]&&(x<hx||(x==hx&&y<hy))))){
				hx=x,hy=y;
			}
		}
	}
	dfs(hx,hy,hx,hy);
}
