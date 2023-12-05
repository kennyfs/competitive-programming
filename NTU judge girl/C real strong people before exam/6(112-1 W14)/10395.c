#include <stdio.h>
#include <stdint.h>
#define ARRAYSIZE 1000
 
typedef struct giantUnsignedInt {
    uint64_t array[ARRAYSIZE];
    int n;
} GiantUnsignedInt;
 
int get(GiantUnsignedInt *giantNum,int i){
	return ((giantNum->array[i/64])>>(64-i%64-1))&1;
}
int numBitChanges(GiantUnsignedInt *giantNum){
	int ans=0;
	for(int i=0;i<(giantNum->n*64)-1;++i){
		ans+=(get(giantNum,i)!=get(giantNum,i+1));
	}
	ans+=(get(giantNum,(giantNum->n*64)-1)!=get(giantNum,0));
	return ans;
}
 
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        GiantUnsignedInt giantNum;
        for (int i = 0; i<n; i++)
            scanf("%lu", &giantNum.array[i]);
        giantNum.n = n;
        printf("%d\n", numBitChanges(&giantNum));
    }
    return 0;
}
