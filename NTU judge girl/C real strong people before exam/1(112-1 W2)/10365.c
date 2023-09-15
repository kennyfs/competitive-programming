#include <stdio.h>
int main(){
	int ax,ay,bx,by,cx,cy,dx,dy;
	int ad,bd,cd;
	while(scanf("%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy)!=EOF){
		ad=(ax-dx)*(ax-dx)+(ay-dy)*(ay-dy);
		bd=(bx-dx)*(bx-dx)+(by-dy)*(by-dy);
		cd=(cx-dx)*(cx-dx)+(cy-dy)*(cy-dy);
		int mind=ad;
		if(bd<mind)mind=bd;
		if(cd<mind)mind=cd;
		if(ad==mind&&bd==mind&&cd==mind)printf("0 ");
		if(ad==mind&&bd!=mind&&cd!=mind)printf("1 ");
		if(ad!=mind&&bd==mind&&cd!=mind)printf("2 ");
		if(ad!=mind&&bd!=mind&&cd==mind)printf("3 ");
		if(ad==mind&&bd==mind&&cd!=mind)printf("4 ");
		if(ad==mind&&bd!=mind&&cd==mind)printf("5 ");
		if(ad!=mind&&bd==mind&&cd==mind)printf("6 ");
	}
}
