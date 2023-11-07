#include <stdio.h>
#include <string.h>
#define int long long
char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char *words[] = {"","thousand","million","billion","trillion","quadrillion","quintillion"};
void print3Digits(int n){
    if(n>100)printf("%s hundred ",ones[n/100]);
    if((n/10)%10==1)printf("%s ",teens[n%10]);
    if((n/10)%10>1)printf("%s-%s ",tens[(n/10)%10],ones[n%10]);
    if((n/10)%10==0&&n)printf("%s ",ones[n%10]);
}
void print(int n,int tnk){
	if(n)print(n/1000,tnk+1);
	print3Digits(n%1000);
	if(n)printf("%s ",words[tnk]);
}
signed main(){
	int n;
	scanf("%lld",&n);
	print(n,0);
}
