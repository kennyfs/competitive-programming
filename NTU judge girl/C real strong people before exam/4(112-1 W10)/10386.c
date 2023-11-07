#include <stdio.h>
#include <string.h>
int calc(char *a,char *b){
	for(char *i=a;*i!='\n';++i){
		char *ptr=strchr(b,*i);
		if(ptr){
			return (i-a)-(ptr-b);
		}
	}
	return 114514;
}
int main(){
	char s[156][1127];
	int n=0,ans=0;
	while(fgets(s[n++],1127,stdin)!=NULL);
	n--;
	for(int i=0;i<n-1;++i){
		ans+=calc(s[i],s[i+1]);
	}
	ans+=calc(s[n-1],s[0]);
	printf("%d",ans);
}
