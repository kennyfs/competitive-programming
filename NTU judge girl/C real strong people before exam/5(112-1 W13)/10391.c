#include <stdio.h>
#define MAXDISK 10
#define NUMROD 3

struct hanoi{
	int stack[3][10],h[3];
};
void initialize(struct hanoi *hn, int n){
	hn->h[0]=hn->h[1]=hn->h[2]=0;
	for(int i=0;i<n;++i){
		hn->stack[0][hn->h[0]++]=n-i-1;
	}
}
void moveHanoi(struct hanoi *hn, int src, int dst){
	hn->stack[dst][hn->h[dst]++]=hn->stack[src][--hn->h[src]];
}
void printHanoi(struct hanoi *hn){
	for(int s=0;s<3;++s){
		printf("%d: ",s);
		for(int i=0;i<hn->h[s];++i){
			printf("%d ",hn->stack[s][i]);
		}
		printf("\n");
	}
	printf("\n");
}
 
void hanoi(struct hanoi *hn, int n, int src, int dst, int buffer){
    if (n == 1) {
        moveHanoi(hn, src, dst);
        printHanoi(hn);
    }
    else {
        hanoi(hn, n - 1, src, buffer, dst);
        moveHanoi(hn, src, dst);
        printHanoi(hn);
        hanoi(hn, n - 1, buffer, dst, src);
    }
}
int main(void){
    int n;
    struct hanoi hn;
    scanf("%d", &n);
    initialize(&hn, n);
    printHanoi(&hn);
    hanoi(&hn, n, 0, 2, 1);
    return 0;
}
