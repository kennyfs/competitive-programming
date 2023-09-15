#include <stdio.h>
int main(){
	int n,x,y,w,h,lastxplus1,lastyplus1,ans=0;
	scanf("%d",&n);
	n--;
	scanf("%d%d%d%d",&x,&y,&w,&h);
	ans+=w*h;
	lastxplus1=x+w;
	lastyplus1=y+h;
	while(n--){
		scanf("%d%d%d%d",&x,&y,&w,&h);
		ans+=h*w;
		ans-=(lastxplus1-x)*(lastyplus1-y);
		lastxplus1=x+w;
		lastyplus1=y+h;
	}
	printf("%d",ans);
}
