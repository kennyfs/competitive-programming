#include <stdio.h>
#include <string.h>
int recur(int id,char match,int firstR,int n,char s[25][156]){
	int ret=-100000,tmp,found=-1;
	if(id==0){
		for(int i=0;i<firstR;++i){
			if(s[0][i]==match){
				found=i;
				break;
			}
		}
		if(found==-1)return -100000;
		return -found;
	}
	for(int i=0;i<strlen(s[id]);++i){
		if(s[id][i]==match){
			found=i;
			break;
		}
	}
	if(found==-1)return -100000;
	for(int i=found;i<strlen(s[id]);++i){
		tmp=recur((id+1)%n,s[id][i],firstR,n,s);
		if(tmp==-100000)continue;
		tmp+=i-found;
		ret=tmp>ret?tmp:ret;
	}
	return ret;
}
int main(){
	char s[25][156];
	int n=0,ans=-100000,tmp;
	while(scanf("%103s", s[n++]) != EOF);
	n--;
	for(int i=0;i<strlen(s[0]);++i){
		tmp=recur(1,s[0][i],i,n,s)+i;
		ans=tmp>ans?tmp:ans;
	}
	printf("%d",ans);
}
