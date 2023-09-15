#include <stdio.h>
int main(){
    int ax,ay,bx,by,ar2,br2;
    int x,y,da2,db2;
    scanf("%d%d%d%d%d%d",&ax,&ay,&ar2,&bx,&by,&br2);
    ar2=ar2*ar2;
    br2=br2*br2;
    while(scanf("%d%d",&x,&y)!=EOF){
        da2=(x-ax)*(x-ax)+(y-ay)*(y-ay);
        db2=(x-bx)*(x-bx)+(y-by)*(y-by);
        if(da2>ar2&&db2>br2)printf("Out\n");
        else if(da2<ar2||db2<br2)printf("In\n");
        else printf("On\n");
    }
}
