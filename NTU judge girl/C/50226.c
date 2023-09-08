#include<stdio.h>
#define int long long
int gcd(int a,int b){
    return a==0?b:gcd(b%a,a);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int max(int a,int b,int c,int d){
    a=(b>a)?b:a;
    b=(c>d)?c:d;
    return (b>a)?b:a;
}
signed main(){
    int a,b,c,d;
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d)!=EOF){
        printf("%lld\n",lcm(lcm(a,b),lcm(c,d))/max(a,b,c,d));
    }    
}
