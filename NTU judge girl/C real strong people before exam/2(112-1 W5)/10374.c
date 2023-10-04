#include <stdio.h>
int main(){
	int n,m,l,w,x,y,s,k,grid[1000][1000];
	scanf("%d%d%d%d%d%d%d%d",&n,&m,&l,&w,&x,&y,&s,&k);
	for(int yy=n-1;yy>=0;--yy)
		for(int xx=0;xx<m;++xx)
			scanf("%d",&grid[xx][yy]);
	int gonestep=(x-m+s)/s>(y-n+s)/s?(x-m+s)/s:(y-n+s)/s;
	gonestep-=2;
	if(gonestep>0){
		x-=gonestep*s;
		y-=gonestep*s;
		k-=gonestep;
	}
	for(int step=0;step<=k;++step){
		if(x+w-1<0||y+l-1<0)break;
		if(m-1>=x&&n-1>=y){
			for(int yy=n-1;yy>=0;--yy){
				for(int xx=0;xx<m;++xx){
					if(xx>=x&&yy>=y&&xx<=x+w-1&&yy<=y+l-1)printf("0 ");
					else printf("%d ",grid[xx][yy]);
				}
				printf("\n");
			}
		}
		printf("\n");
		x-=s;
		y-=s;
	}
}
