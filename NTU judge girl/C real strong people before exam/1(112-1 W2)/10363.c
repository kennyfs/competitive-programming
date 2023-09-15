#include <stdio.h>
int main(){
	int n,x,y,x1,y1,lastx,lasty,ans=0;
	scanf("%d",&n);
	n--;
	scanf("%d%d",&x1,&y1);
	lastx=x1;
	lasty=y1;
	while(n--){
		scanf("%d%d",&x,&y);
		ans+=lastx*y-lasty*x;
		lastx=x;
		lasty=y;
	}
	ans+=x*y1-y*x1;
	ans=ans<0?-ans:ans;
	printf("%d",ans);
}
