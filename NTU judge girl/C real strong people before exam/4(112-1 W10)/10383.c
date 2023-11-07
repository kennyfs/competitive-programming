#include <stdio.h>
#include <string.h>
int main(){
	char s[114514];
	char *reserved[12]={"if", "else", "while", "for", "switch", "case", "break", "return", "void", "int", "float", "char"};
	char names[30][30];int ind=0,cnt[30];
	for(int i=0;i<30;++i){
		names[i][0]='\0';
		cnt[i]=0;
	}
	while(fgets(s,100156,stdin)!=NULL){
		char *token=strtok(s," #!?:&|<>~^(){}[],;=+-*/\n");
		for(;token!=NULL;token=strtok(NULL," #!?:&|<>~^(){}[],;=+-*/\n")){
			int ok=1;
			for(int i=0;i<12;++i){
				if(strcmp(reserved[i],token)==0){ok=0;break;}
			}
			if(!ok)continue;
			if(!((token[0]>='a'&&token[0]<='z')||(token[0]>='A'&&token[0]<='Z')||token[0]=='_'))continue;
			ok=0;
			for(int i=0;i<ind;++i){
				if(strncmp(names[i],token,24)==0){
					cnt[i]++;
					ok=1;break;
				}
			}
			if(ok)continue;
			strncpy(names[ind],token,24);
			cnt[ind]=1;
			ind++;
		}
	}
	for(int i=0;i<ind;++i){
		printf("%s %d\n",names[i],cnt[i]);
	}
}
