#include <stdio.h>
#include <string.h>
int main(){
	char s[114514];
	char *suffix[20]={"able", " ary", "  ed", "ence", " ful", "hood", "ical", " ing", " ish", " ism", " ist", " ive", " ize", "less", "  ly", "ment", "ness", " ous", "ship", "tion"};
	int cnt[20];
	for(int i=0;i<20;++i)cnt[i]=0;
	while(fgets(s,100156,stdin)!=NULL){
		char *ptr=strtok(s," ,.!?;:\n");
		while(ptr!=NULL){
			int ans=-1;
			for(int i=0;i<20;++i){
				int ok=1;
				int ind=strlen(ptr),j=0;
				for(;j<4&&suffix[i][4-j-1]!=' ';j++){
					if(suffix[i][4-j-1]!=ptr[ind-j-1]){ok=0;break;}
				}
				if(!ok)continue;
				ans=i;
				break;
			}
			if(ans>=0)cnt[ans]++;
			ptr=strtok(NULL," ,.!?;:\n");
		}
	}
	for(int i=0;i<20;++i){
		if(cnt[i]){
			int ind=0;
			while(suffix[i][ind]==' ')ind++;
			for(;ind<4;ind++)printf("%c",suffix[i][ind]);
			printf(":\nFrequency: %d\n",cnt[i]);
		}
	}
}
