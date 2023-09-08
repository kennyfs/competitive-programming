#include<stdio.h>
int main(){
  int a,b,c,d,e;
  scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
  printf("%d\n%d",2*(a*b+b*c+c*a)+d*(8*(a+b+c)-48*e),a*b*c-2*(a-2*e)*(b-2*e)*d-2*(b-2*e)*(c-2*e)*d-2*(c-2*e)*(a-2*e)*d);
}
