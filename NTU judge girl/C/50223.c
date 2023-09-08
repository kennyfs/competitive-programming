#include<stdio.h>
int main(){
  int w,a,b,c,d,e;
  scanf("%d%d%d%d%d%d",&w,&a,&b,&c,&d,&e);
  int total_length=(b==0)?a+((d>e)?d:e)*2+2+c:a+(d+e)*2+b+c+2;
  printf("%d",w*w+total_length*total_length);
}
