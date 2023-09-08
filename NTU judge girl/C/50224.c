#include<stdio.h>
int main(){
  int now,best;
  scanf("%d",&best);
  while(scanf("%d",&now)!=EOF){
    int suma=0,sumb=0,tmpa=now,tmpb=best,numa=0,numb=0;
    while(tmpa>0){
      numa++;
      suma+=tmpa%10;
      tmpa/=10;
    }
    while(tmpb>0){
      numb++;
      sumb+=tmpb%10;
      tmpb/=10;
    }
    if(suma>sumb||(suma==sumb&&(numa<numb||(numa==numb&&now>best))))best=now;
  }
  printf("%d",best);
}
