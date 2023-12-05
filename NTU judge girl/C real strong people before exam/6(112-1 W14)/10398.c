#include <stdio.h>
#include <string.h>
int recur(int num,int rem,int numToChar[10],int used[10],int who[10],int cnt[30]){
	if(num==10){
		if(rem==0){
			for(int i=1;i<=9;++i){
				printf("%c ",numToChar[i]+'a');
			}
			return 1;
		}
		return 0;
	}
	for(int i=1;i<=9;++i){
		if(used[i]||cnt[who[i]]*num>rem)continue;
		used[i]=1;
		numToChar[num]=who[i];
		if(recur(num+1,rem-cnt[who[i]]*num,numToChar,used,who,cnt))return 1;
		used[i]=0;
	}
	return 0;
}
int main(){
	int k,l=1,cnt[30]={0},who[10];
	char s[156];
	scanf("%d",&k);
	while(fgets(s,156,stdin)!=NULL){
		for(int i=0;i<strlen(s);i++){
			cnt[s[i]-'a']++;
		}
	}
	
	for(int i=0;i<26;++i){
		if(cnt[i]){
			who[l++]=i;
		}
	}
	int used[10]={0},numToChar[10];
	recur(1,k,numToChar,used,who,cnt);
}
