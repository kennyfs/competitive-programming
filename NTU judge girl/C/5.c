#include <stdio.h>
signed main(){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  printf("%d\n%d",2*(a*b+b*c+c*a),a*b*c);
}
