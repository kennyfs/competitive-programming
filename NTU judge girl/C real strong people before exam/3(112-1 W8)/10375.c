#include <stdio.h>
#include <stddef.h>
#define MAX_PTR_ARR_SIZE 1000

int countIntersections(int* ptrArray[]){
    int *min=ptrArray[0];
    int i=1,n;
    while(ptrArray[i]!=NULL){
        min=ptrArray[i]-min>0?min:ptrArray[i];
        i++;
    }
    n=i;
    int indexes[MAX_PTR_ARR_SIZE];
    for(i=0;i<n;++i)
        indexes[i]=ptrArray[i]-min;
    int ans=0;
    for(i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(indexes[i]>indexes[j])ans++;
        }
    }
    return ans;
}
#define MAX_ARR_SIZE 10000
int main(void) {
    int array[MAX_ARR_SIZE];
    int *ptrArray[MAX_PTR_ARR_SIZE];
    for (int i = 0; i < MAX_ARR_SIZE; i++) {
        array[i] = 0;
    }
    int n;
    scanf("%d", &n);
    int index[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &index[i]);
        ptrArray[i] = &array[index[i]];
    }
    ptrArray[n] = NULL;
    int numIntersections = countIntersections(ptrArray);
    printf("%d\n", numIntersections);
    return 0;
}
