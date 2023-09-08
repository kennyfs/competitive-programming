#include<stdio.h>
int main(){
  int n,m,k,index=0,nowx=1,nowy=1;
  scanf("%d%d%d",&n,&m,&k);
  while(1){
    if(index+(m-nowy+1)>=k){
      printf("%d %d",nowx,nowy+(k-index)-1);
      break;
      }
    index+=m-nowy+1;
    nowx++;
    if(index+(n-nowx+1)>=k){
      printf("%d %d",nowx+(k-index)-1,nowy);
      break;
      }
    index+=n-nowx+1;
    nowy++;
  }
}
