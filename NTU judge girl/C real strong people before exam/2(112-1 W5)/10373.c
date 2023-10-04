#define MAXR 100
#define MAXC 100
#define MAXK 10
void img2col(int r, int c, int k, int imgMatrix[MAXR][MAXC], int colMatrix[MAXR * MAXC][MAXK * MAXK]){
	int outputIndexX=0,outputIndexY=0;
	for(int y=0;y<=c-k;++y){
		for(int x=0;x<=r-k;++x){
			outputIndexY=0;
			for(int winy=0;winy<k;++winy){
				for(int winx=0;winx<k;++winx){
					colMatrix[outputIndexX][outputIndexY++]=imgMatrix[x+winx][y+winy];
				}
			}
			outputIndexX++;
		}
	}
}
