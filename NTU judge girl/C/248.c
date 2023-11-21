#include <stdio.h>
int check(int x,int y,int num[9][9],int ans[9][9]){
	if(x>=9||y>=9||x<0||y<0)return 1;
	int ones=0,blank=0;
	for(int dx=-1;dx<=1;++dx){
		for(int dy=-1;dy<=1;++dy){
			int tx=x+dx,ty=y+dy;
			if(tx>=9||ty>=9||tx<0||ty<0)continue;
			if(ans[tx][ty]==1)ones++;
			else if(ans[tx][ty]==-1)blank++;
		}
	}
	if(ones+blank<num[x][y]||ones>num[x][y])return 0;
	return 1;
}
int solve(int x,int y,int num[9][9],int ans[9][9]){
	if(x==9&&y==0)return 1;
	int ok=0;
	ans[x][y]=1;
	if(check(x,y,num,ans)&&check(x-1,y-1,num,ans)&&check(x-1,y,num,ans)&&check(x-1,y+1,num,ans)&&check(x,y-1,num,ans)){
		if(y==8)ok|=solve(x+1,0,num,ans);
		else ok|=solve(x,y+1,num,ans);
	}
	if(ok)return 1;
	ans[x][y]=0;
	if(check(x,y,num,ans)&&check(x-1,y-1,num,ans)&&check(x-1,y,num,ans)&&check(x-1,y+1,num,ans)&&check(x,y-1,num,ans)){
		if(y==8)ok|=solve(x+1,0,num,ans);
		else ok|=solve(x,y+1,num,ans);
	}
	if(ok)return 1;
	ans[x][y]=-1;
	return 0;
}
int main(){
	int num[9][9],ans[9][9];
	for(int x=0;x<9;++x){
		for(int y=0;y<9;++y){
			scanf("%d",&num[x][y]);
			ans[x][y]=-1;
		}
	}
	if(!solve(0,0,num,ans)){printf("no solution\n");return 0;}
	for(int x=0;x<9;++x){
		for(int y=0;y<9;++y){
			if(y<8)printf("%d ",ans[x][y]);
			else printf("%d",ans[x][y]);
		}
		if(x<8)printf("\n");
	}
}
