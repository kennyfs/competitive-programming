void dividePolynomial(int f[], int g[]){
	int quo[2156],rem[2156];
	for(int step=0;step<2156;step++)
		quo[step]=rem[step]=0;
	quo[0]=f[0]-g[0];
	for(int step=0;step<quo[0]+1;step++){
		quo[step+1]=f[step+1]/g[1];
		for(int stepdi=0;stepdi<g[0]+1;stepdi++){
			f[step+stepdi+1]-=g[stepdi+1]*quo[step+1];
		}
		if(f[step+1]!=0)printf("I am so stupid QQ\n");
	}
	// remainder is f's index from f[0]-g[0]+1 to f[0]
	rem[0]=g[0]-1;
	for(int step=f[0]-g[0]+1;step<=f[0];step++){
		if(f[step+1]==0){
			rem[0]--;
			continue;
		}
		for(int steprem=0;step<=f[0];step++,steprem++)
			rem[steprem+1]=f[step+1];
		break;
	}
	if(rem[0]==-1)rem[0]=0;
	for(int step=0;step<2000;step++){
		f[step]=quo[step];
		g[step]=rem[step];
	}
}
