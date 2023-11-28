#include <stdio.h>
typedef struct Puzzle Puzzle;
struct Puzzle{
	int grid[4][4];
	int bx,by;
};
void initPuzzle(Puzzle *puzzle, int grid[4][4]){
	for(int i=0;i<16;++i){
		puzzle->grid[i/4][i%4]=grid[i/4][i%4];
		if(grid[i/4][i%4]==0)
			puzzle->bx=i/4,puzzle->by=i%4;
	}
}
void movePiece(Puzzle *puzzle, char direction){
	int dx,dy;
	switch(direction){
		case 'U':
			dx=-1,dy=0;
			break;
		case 'D':
			dx=1,dy=0;
			break;
		case 'L':
			dx=0,dy=-1;
			break;
		case 'R':
			dx=0,dy=1;
			break;
	}
	int tx=puzzle->bx+dx,ty=puzzle->by+dy;
	if(tx>=4||ty>=4||tx<0||ty<0){
		printf("Invalid move\n");
		return;
	}
	puzzle->grid[puzzle->bx][puzzle->by]=puzzle->grid[tx][ty];
	puzzle->grid[tx][ty]=0;
	puzzle->bx=tx;
	puzzle->by=ty;
	for(int x=0;x<4;++x){
		for(int y=0;y<4;++y){
			printf("%d ",puzzle->grid[x][y]);
		}
		printf("\n");
	}
}

int main() {
    int grid[4][4] = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    Puzzle puzzle;
    initPuzzle(&puzzle, grid);
    int numMoves;
    scanf("%d", &numMoves);
    char move;
    for (int i = 0; i < numMoves; i++) {
        scanf(" %c", &move);
        movePiece(&puzzle, move);
    }
    return 0;
}
