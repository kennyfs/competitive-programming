#include <stdio.h>
#include <stdint.h>
void recur(uint64_t now,int index,int chosen,int *ans,uint64_t *ansbits,int n,int m,int relations[40][2],int adj[65][65]){
	if(index==m){
		if(chosen>*ans){
			*ans=chosen;
			*ansbits=now;
		}
		return;
	}
	if(chosen+(m-index)+1<=*ans)return;
	int u=relations[index][0],v=relations[index][1],ok=1;
	for(int i=0;i<n;++i){
		if(adj[i][u]&&adj[i][v]){
			ok=0;
			break;
		}
	}
	if(ok){
		adj[u][v]=adj[v][u]=1;
		recur(now|(1<<index),index+1,chosen+1,ans,ansbits,n,m,relations,adj);
		adj[u][v]=adj[v][u]=0;
	}
	recur(now,index+1,chosen,ans,ansbits,n,m,relations,adj);
}
int main(){
	int n,m;
	int relations[40][2]={0};
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		scanf("%d%d",&relations[i][0],&relations[i][1]);
	}
	uint64_t ansbits;
	int ans=0,adj[65][65]={0};
	recur(0,0,0,&ans,&ansbits,n,m,relations,adj);
	for(int i=0;i<m;++i){
		if((ansbits>>i)&1)printf("%d %d\n",relations[i][0],relations[i][1]);
	}
}
