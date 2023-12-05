#include <stdio.h>
void recur2(int idx,int dph,int startidx,int tmpidx,int tmplst[1156],int *anslen,int anslst[1156],int vis[1156],int n,int m,int k,int sz[1156],int adj[1156][60]);
void recur1(int idx,int tmpidx,int tmplst[1156],int *anslen,int anslst[1156],int vis[1156],int n,int m,int k,int sz[1156],int adj[1156][60]){
	if(tmpidx+(m-idx)*k<*anslen)return;
	if(idx==m){
		if(tmpidx>*anslen){
			*anslen=tmpidx;
			for(int i=0;i<tmpidx;++i){
				anslst[i]=tmplst[i];
			}
		}
		return;
	}
	vis[idx]=1;
	tmplst[tmpidx]=idx;
	recur2(idx,0,idx,tmpidx+1,tmplst,anslen,anslst,vis,n,m,k,sz,adj);
	vis[idx]=0;
	recur1(idx+1,tmpidx,tmplst,anslen,anslst,vis,n,m,k,sz,adj);
}
void recur2(int idx,int dph,int startidx,int tmpidx,int tmplst[1156],int *anslen,int anslst[1156],int vis[1156],int n,int m,int k,int sz[1156],int adj[1156][60]){
	if(dph==k-1){
		recur1(startidx+1,tmpidx,tmplst,anslen,anslst,vis,n,m,k,sz,adj);
		return;
	}
	for(int i=0;i<sz[idx];++i){
		int u=adj[idx][i];
		if(vis[u])continue;
		vis[u]=1;
		tmplst[tmpidx]=u;
		recur2(u,dph+1,startidx,tmpidx+1,tmplst,anslen,anslst,vis,n,m,k,sz,adj);
		vis[u]=0;
	}
}
int main(){
	int n,m,k,e;
	scanf("%d%d%d",&k,&n,&e);
	m=n/k;
	int adj[1156][60],sz[1156]={0};
	while(e--){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u][sz[u]++]=v;
	}
	int tmplst[1156],anslen=0,anslst[1156],vis[1156]={0};
	recur1(0,0,tmplst,&anslen,anslst,vis,n,m,k,sz,adj);
	for(int i=0;i<anslen;++i){
		printf("%d ",anslst[i]);
		if(i%k==k-1)printf("\n");
	}
}
