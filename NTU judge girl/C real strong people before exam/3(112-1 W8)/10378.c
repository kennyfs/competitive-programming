#include <stdio.h>

#define MAX 500

void rotate(int *P[MAX][MAX], int n){
    int *answer[MAX][MAX];
    for(int x=0;x<n;++x){
        for(int y=0;y<n;++y){
            answer[x][y]=P[n-y-1][x];
        }
    }
    for(int x=0;x<n;++x){
        for(int y=0;y<n;++y){
            P[x][y]=answer[x][y];
        }
    }
}

int main() {
    int array[MAX][MAX], check[MAX][MAX];
    int *P[MAX][MAX];

    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            P[i][j] = &array[i][j];
            scanf("%d", &array[i][j]);
            check[i][j] = array[i][j];
        }
    }

    rotate(P, n);

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            printf("%d ", *(P[i][j]));
        }
        printf("\n");
    }

    return 0;
}
