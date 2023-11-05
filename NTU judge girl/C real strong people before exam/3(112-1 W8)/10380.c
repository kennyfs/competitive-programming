#include <stdio.h>

void Turing_Machine(int *head, int K){
    int move[3][4]={{1,1,1,1},{-1,1,-1,1},{0,-1,1,0}};
    int nextState[3][4]={{2,1,2,1},{2,0,2,0},{1,0,1,0}};
    int s=0;
    while(K--){
        int headDelta=move[s][*head];
        int news=nextState[s][*head];
        head[0]=(s+*head>=4)?s+*head-4:s+*head;
        head+=headDelta;
        s=news;
    }
}

int main()
{
    int n, p, K;
    scanf("%d%d%d", &n, &p, &K);
    int tape[n];
    for(int i = 0; i < n; i++) scanf("%d", &tape[i]);

    int *head = &tape[p];
    Turing_Machine(head, K);

    for(int i = 0; i < n; i++) printf("%d ", tape[i]);

    return 0;
}
