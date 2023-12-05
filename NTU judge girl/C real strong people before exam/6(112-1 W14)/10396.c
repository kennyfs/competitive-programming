#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
	return a>b?a:b;
}
void recur(int index,int tmpbits[20],int curmax,int used[20],int *ans,int ansbits[20],int n,int edges[156][2],int adj[20][20]){
	if(index>n)return;
	for(int i=1;i<=n;++i){
		if(used[i])continue;
		int tmpmax=curmax;
		for(int v=1;v<=n;++v){
			if((!adj[index][v])||(tmpbits[v]==0))continue;
			tmpmax=max(tmpmax,abs(tmpbits[v]-i));
		}
		if(tmpmax>*ans)continue;
		tmpbits[index]=i;
		used[i]=1;
		if(index==n){
			if(tmpmax<*ans){
				*ans=tmpmax;
				for(int j=1;j<=n;++j)ansbits[j]=tmpbits[j];
			}
		}
		recur(index+1,tmpbits,tmpmax,used,ans,ansbits,n,edges,adj);
		used[i]=0;
		tmpbits[index]=0;
	}
}
int main(){
	int n,m,edges[156][2],adj[20][20]={0};
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		scanf("%d%d",&edges[i][0],&edges[i][1]);
		adj[edges[i][0]][edges[i][1]]=adj[edges[i][1]][edges[i][0]]=1;
	}
	int ansbits[20]={0},tmpbits[20]={0},used[20]={0},ans=99999999;
	recur(1,tmpbits,0,used,&ans,ansbits,n,edges,adj);
	for(int i=1;i<=n;++i)printf("%d ",ansbits[i]);
}
