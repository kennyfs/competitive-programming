#include <stdio.h>
int main(){
	int input;
	int nowcnt=0;
	while(scanf("%d",&input)!=EOF){
		if((input>0&&nowcnt<0)||(input<0&&nowcnt>0)){
			printf("%d ",nowcnt);
			nowcnt=0;
		}
		nowcnt+=(input>0)-(input<0);
	}
	if(nowcnt!=0)printf("%d ",nowcnt);
}
