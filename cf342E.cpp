#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int MAXN=100010;
int n,m;
int cnt=0,sz[MAXN],cendep[MAXN],dep[MAXN],cenfa[MAXN],neard[MAXN];
bool visited[MAXN];
vector<int> G[MAXN];
int cenanc[MAXN][20],anc[MAXN][20];
void dfs(int x,int f){
	dep[x]=dep[f]+1;
    anc[x][0]=f;
    for(int i:G[x]){
        if(i!=f)dfs(i,x);
    }
}
void initanc(){//for origin tree
	for(int j=1;j<20;++j){//2^20 is about 10^6, enough for 10^5 dots
		anc[0][j]=0;
		for(int i=1;i<=n;++i){
			anc[i][j]=anc[anc[i][j-1]][j-1];
		}
	}
}
int findlca(int a,int b){
	if(dep[a]>dep[b])swap(a,b);//dep[a] must be <= dep[b]
	int tomove=dep[b]-dep[a];
	for(int c=0;tomove;++c){
		if(tomove%2)
			b=anc[b][c];
		tomove/=2;
	}
	for(int j=__lg(n);j>=0;--j){
		if(anc[a][j]!=anc[b][j])
			a=anc[a][j],
			b=anc[b][j];
	}
	if(a==b)return a;
	return anc[a][0];
}
void initcenanc(){//for centree // do getcentree first(surely)
	for(int i=1;i<=n;++i)cenanc[i][0]=cenfa[i];
	for(int j=1;j<20;++j){//2^20 is about 10^6, enough for 10^5 dots
		cenanc[0][j]=0;
		for(int i=1;i<=n;++i){
			cenanc[i][j]=cenanc[cenanc[i][j-1]][j-1];
		}
	}
}
int findcenlca(int a,int b){
	if(cendep[a]>cendep[b])swap(a,b);//cendep[a] must be <= cendep[b]
	int tomove=cendep[b]-cendep[a];
	for(int c=0;tomove;++c){
		if(tomove%2)
			b=cenanc[b][c];
		tomove/=2;
	}
	for(int j=__lg(n);j>=0;--j){
		if(cenanc[a][j]!=cenanc[b][j])
			a=cenanc[a][j],
			b=cenanc[b][j];
	}
	if(a==b)return a;
	return cenanc[a][0];
}
void getsz(int x,int f){
    sz[x]=1;
    for(int i:G[x]){
        if(i==f||visited[i])continue;
        getsz(i,x);
        sz[x]+=sz[i];
    }
}
int findcentroid(int x,int f,int s){//重心樹的x找重心樹的子節點
    for(int i:G[x]){
        if(2*sz[i]>=s&&!visited[i]&&i!=f)// sz[i]>= s/2
			return findcentroid(i,x,s);
			//only one node has a sz >= s/2
    }
    return x;
}
void getcentree(int x,int f,int d){
	getsz(x,f);
	int cen=findcentroid(x,f,sz[x]);
	cendep[cen]=d;
	visited[cen]=1;
	cenfa[cen]=f;
	for(int i:G[cen]){
		if(!visited[i])getcentree(i,cen,d+1);
	}
}
int dist(int a,int b){
	int l=findlca(a,b);
	return dep[a]+dep[b]-2*dep[l];
}
void paint(int v){
	int x=v;
	while(x){
		neard[x]=min(neard[x],dist(v,x));
		x=cenfa[x];
	}
}
int finaldist(int v){
	int ans=8e7,x=v;
	while(x){
		ans=min(ans,dist(x,v)+neard[x]);
		x=cenfa[x];
	}
	return ans;
}
int main(){Hirasawa_Yui_My_Wife
    cin>>n>>m;
    int u,v;
    for(int i=0;i<n-1;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    initanc();
    fill(visited,visited+MAXN,0);
    getcentree(1,0,n);
    initcenanc();
	fill(neard,neard+MAXN,8e7);
	paint(1);
    while(m--){
        cin>>u>>v;
        if(u==1){
			paint(v);
        }else{
			cout<<finaldist(v)<<'\n';
        }
    }
}
