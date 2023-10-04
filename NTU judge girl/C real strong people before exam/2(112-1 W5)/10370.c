#include <stdio.h>
int n,m,x,y,sq[156][156],dirlen[4],quests[156][156];
int check(int x,int y,int dir){
	int len=0;
	while(x>=0&&y>=0&&x<n&&y<n&&sq[x][y]){
		len++;
		switch(dir){
			case 0:x++;break;
			case 1:x--;break;
			case 2:y++;break;
			case 3:y--;break;
		}
	}
	return len;
}
int main(){
	scanf("%d",&n);
	for(x=0;x<n;++x){
		for(y=0;y<n;++y){
			scanf("%d",&sq[x][y]);
		}
	}
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		scanf("%d%d",&x,&y);
		quests[x][y]=1;
	}
	for(x=0;x<n;++x){
		for(y=0;y<n;++y){
			if(!quests[x][y])continue;
			for(int dir=0;dir<4;++dir)dirlen[dir]=check(x,y,dir);
			if(dirlen[1]>1&&dirlen[2]>1)printf("0 %d %d\n",dirlen[1],dirlen[2]);
			else if(dirlen[1]>1&&dirlen[3]>1)printf("1 %d %d\n",dirlen[1],dirlen[3]);
			else if(dirlen[0]>1&&dirlen[3]>1)printf("2 %d %d\n",dirlen[0],dirlen[3]);
			else if(dirlen[0]>1&&dirlen[2]>1)printf("3 %d %d\n",dirlen[0],dirlen[2]);
			else printf("assert false %d",100/0);
		}
	}
}
