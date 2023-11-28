#include <stdio.h>
void recur(int l,int x,int y,int z,int cx,int cy,int cz){
	int hx,hy,hz;
	hx=(cx-x)<l/2;
	hy=(cy-y)<l/2;
	hz=(cz-z)<l/2;
	int p=hx+hy*2+hz*4;
	printf("%d %d %d %d\n",p+1,x+l/2,y+l/2,z+l/2);
	if(l==2)return;
	for(int i=0;i<8;++i){
		if(i==p)
			recur(l/2,x+(l/2)*(1-hx),y+(l/2)*(1-hy),z+(l/2)*(1-hz),cx,cy,cz);
		else
			recur(l/2,x+(l/2)*((i&1)==0),y+(l/2)*((i&2)==0),z+(l/2)*((i&4)==0),x+l/2-((i&1)>0),y+l/2-((i&2)>0),z+l/2-((i&4)>0));
	}
}
int main(){
	int l,x,y,z;
	scanf("%d%d%d%d",&l,&x,&y,&z);
	recur(l,0,0,0,x,y,z);
}
