#include <stdio.h>

#include <stdint.h>
#define ARRAYSIZE 1000
 
int max(int a,int b){
	return a>b?a:b;
}
typedef struct giantUnsignedInt {
    uint64_t array[ARRAYSIZE];
    int n;
} GiantUnsignedInt;
int get(GiantUnsignedInt *giantNum,int i){
	return ((giantNum->array[i/64])>>(64-i%64-1))&1;
}
int numZeroBits(GiantUnsignedInt *giantNum){
	int now=0,ans=0;
	for(int i=0;i<(giantNum->n*64);++i){
		if(get(giantNum,i))ans=max(ans,now),now=0;
		else now++;
	}
	ans=max(ans,now);
	return ans;
}
 
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        GiantUnsignedInt giantNum;
        for (int i = 0; i<n; i++)
            scanf("%lu", &giantNum.array[i]);
        giantNum.n = n;
        printf("%d\n", numZeroBits(&giantNum));
    }
    return 0;
}
