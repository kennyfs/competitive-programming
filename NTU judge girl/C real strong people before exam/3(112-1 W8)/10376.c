#include <stdio.h>
#include <stdlib.h>

int calRectArea(int n, int m, int* ptrMat, int* ptrLeft[], int* ptrRight[]){
    int x,y,lastx,lasty,rightx,righty,ans;
    x=(ptrLeft[0]-ptrMat)/n;
    y=(ptrLeft[0]-ptrMat)%n;
    rightx=(ptrRight[0]-ptrMat)/n;
    righty=(ptrRight[0]-ptrMat)%n;
    ans=(rightx-x+1)*(righty-y+1);
    for(int i=0;i<m;++i){
        lastx=rightx;
        lasty=righty;
        x=(ptrLeft[i]-ptrMat)/n;
        y=(ptrLeft[i]-ptrMat)%n;
        rightx=(ptrRight[i]-ptrMat)/n;
        righty=(ptrRight[i]-ptrMat)%n;
        ans+=(rightx-x+1)*(righty-y+1);
        ans-=(lastx-x+1)*(lasty-y+1);
    }
    return ans;
}

#define MAXM 200

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    int *ptrMatrix;
    int matrix[N][N];
    int *ptrLeft[MAXM];
    int *ptrRight[MAXM];
    int x, y, w, h;

    ptrMatrix = &matrix[0][0];
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d%d", &x, &y, &w, &h);
        ptrLeft[i] = &matrix[x][y];
        ptrRight[i] = &matrix[x + w - 1][y + h - 1];
    }
    int area = calRectArea(N, M, ptrMatrix, ptrLeft, ptrRight);
    printf("%d\n", area);
}
