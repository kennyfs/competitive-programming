#include <stdio.h>
#include <string.h>
int read(char *str,char **ptr){
	int ind=0;
	ptr[ind]=strtok(str," ,.!?;:[](){}\n");
	while(ptr[ind]!=NULL)
		ptr[++ind]=strtok(NULL," ,.!?;:[](){}\n");
	return ind;
}
int main(){
	char s1[100156],s2[100156];
	char *p1[1156],*p2[1156];
	fgets(s1,100156,stdin);
	fgets(s2,100156,stdin);
	int n1=read(s1,p1);
	int n2=read(s2,p2);
	int i=0,j=0;
	while(i<=n1&&j<=n2){
		if(i==n1){
			for(;j<n2;++j)printf("%s",p2[j]);
			break;
		}
		if(j==n2){
			for(;i<n1;++i)printf("%s",p1[i]);
			break;
		}
		int cmp=strcmp(p1[i],p2[j]);
		if(cmp<0)printf("%s",p1[i++]);
		else if(cmp>0)printf("%s",p2[j++]);
		else while(1);
	}
}
