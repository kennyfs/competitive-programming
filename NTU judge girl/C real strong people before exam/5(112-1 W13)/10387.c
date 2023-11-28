#include <stdio.h>
int ok(int board[],int n,int m,int p){
	if(board[p])return 0;
	int d[4][2]={{-2,-1},{-2,1},{-1,-2},{-1,2}};
	int x=p/m,y=p%m;
	for(int i=0;i<4;++i){
		int tx=x+d[i][0],ty=y+d[i][1];
		if(ty>=m||tx<0||ty<0)continue;
		if(board[tx*m+ty]==2)return 0;
	}
	return 1;
}
void recur(int board[],int n,int m,int p,int prev,int *ans){
	if((n*m-p)/2+prev<*ans)return;
	if(p>=n*m){
		if(prev>*ans)*ans=prev;
		return;
	}
	if(ok(board,n,m,p)){
		board[p]=2;
		recur(board,n,m,p+1,prev+1,ans);
		board[p]=0;
	}
	recur(board,n,m,p+1,prev,ans);
}
int main(){
	int n,m,x,y;
	int board[256]={0};
	scanf("%d%d",&n,&m);
	while(scanf("%d%d",&x,&y)==2){
		board[x*m+y]=1;
	}
	int ans=0;
	recur(board,n,m,0,0,&ans);
	printf("%d",ans);
}
