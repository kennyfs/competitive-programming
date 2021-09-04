#include "lib1895.h"
#include <cstring>
int const N=2e6+10;
int seg[4*N],segmi[4*N],segma[4*N];
void buildWall(int n,int k,int* op,int* left,int* right,int *hei,int* ans){
	memset(seg,0,sizeof(seg));
	memset(segmi,0,sizeof(segmi));
	memset(segma,0,sizeof(segma));
	for(int i=0;i<k;++i){
		switch(op[i]){
			case 1:
				add(1,0,left[i],right[i],hei[i]);
				break;
			case 2:
				break;
		}
	}
}
