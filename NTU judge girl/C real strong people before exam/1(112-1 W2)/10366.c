#include <stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    while(a>1){
        printf("%d\n",a);
        if(a&1)a=(a<<1)+a+1;
        else a>>=1;
    }
    printf("1");
}
