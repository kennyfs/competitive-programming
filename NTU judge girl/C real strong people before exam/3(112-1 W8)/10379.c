#include <stdio.h>
#include <assert.h>

#include <stddef.h>
#define MAX 1000

void permute(int *ptrArray[MAX], int *ptrPerms[MAX]){
    int n,m,arrayIdx=0,premIdx=0;
    while(ptrArray[arrayIdx]!=NULL)arrayIdx++;
    while(ptrPerms[premIdx]!=NULL)premIdx++;
    n=arrayIdx;
    m=premIdx;
    int *myptr[2][MAX],a=1,b=0,c;
    for(int i=0;i<n;++i)myptr[0][i]=ptrArray[i];
    for(int q=0;q<m;q++){
        c=a;a=b;b=c;//swap(a,b). always a to b
        for(int i=0;i<n;++i)myptr[b][i]=myptr[a][ptrPerms[q][i]];
        premIdx++;
    }
    for(int i=0;i<n;++i)ptrArray[i]=myptr[b][i];
}

int main() {
    int n, array[MAX], check[MAX];
    int *ptrArray[MAX];
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        ptrArray[i] = &array[i];
        scanf("%d", &array[i]);
        check[i] = array[i];
    }
    ptrArray[n] = NULL;

    int m, perms[MAX][MAX];
    int *ptrPerms[MAX];
    scanf("%d", &m);
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++)
            scanf("%d", &perms[i][j]);
        ptrPerms[i] = perms[i];
    }
    ptrPerms[m] = NULL;

    permute(ptrArray, ptrPerms);

    for (int i = 0; i<n; i++) {
        assert(array[i] == check[i]);
        printf("%d ", *(ptrArray[i]));
    }

    return 0;
}
