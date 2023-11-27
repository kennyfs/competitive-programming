#include <stdio.h>
void recur(int l,int x,int y,int cx,int cy){
	if(l==1)return;
	int hx,hy;
	hx=(cx-x)<l/2;
	hy=(cy-y)<l/2;
	int p=hx+hy*2;
	printf("%d %d %d\n",p+1,x+l/2,y+l/2);
	for(int i=0;i<4;++i){
		if(i==p)
			recur(l/2,x+(l/2)*(1-hx),y+(l/2)*(1-hy),cx,cy);
		else
			recur(l/2,x+(l/2)*((i&1)==0),y+(l/2)*((i&2)==0),x+l/2-((i&1)>0),y+l/2-((i&2)>0));
	}
	return;
}
int main(){
	int l,x,y;
	scanf("%d%d%d",&l,&x,&y);
	recur(l,0,0,x,y);
}
