#include <stdio.h>
void count_collision(int *ptr[], int A[], int n, int a, int b, int c){
    for(int i=0;i<c;++i)A[i]=0;
    for(int i=0;i<n;++i){
        int F=(a*i+b)%c;
        A[F]++;
        ptr[i]=A+F;
    }
    for(int i=0;i<c;++i)
        if(A[i]>0)
            A[i]--;
}

int main()
{
    int n;
    int a, b, c;
    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);

    int *ptr[n];
    int A[c];

    count_collision(ptr, A, n, a, b, c);

    for(int i = 0; i < c; i++) printf("%d ", A[i]);
    printf("\n");
    for(int i = 0; i < n; i++) printf("%d ", ptr[i] - A);

    return 0;
}
