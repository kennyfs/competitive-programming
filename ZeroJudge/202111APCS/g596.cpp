#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e4+10;
int n,m,h;
bool xline[N][N],yline[N][N],dot[N][N];
int nxt[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>h;
	int ans,mx=-1;
	while(h--){
		int x,y,op,tx,ty;
		cin>>x>>y>>op;
		++x;++y;
		switch(op){
			case 0:
				dot[x][y]=1;
				if(!xline[x][y]){
					for(int d=0;d<2;++d){
						tx=x,ty=y;
						bool flag=0;
						while(1){
							tx+=nxt[d][0];ty+=nxt[d][1];
							if(tx>n||ty>m||tx<1||ty<1)break;
							if(dot[tx][ty]){flag=1;break;}
						}
						if(flag){
							while(1){
								tx-=nxt[d][0];ty-=nxt[d][1];
								if(tx>n||ty>m||tx<1||ty<1)break;
								if(tx==x&&ty==y)break;
								xline[tx][ty]=1;
							}
						}
					}
				}else xline[x][y]=0;
				if(!yline[x][y]){
					for(int d=2;d<4;++d){
						tx=x,ty=y;
						bool flag=0;
						while(1){
							tx+=nxt[d][0];ty+=nxt[d][1];
							if(tx>n||ty>m||tx<1||ty<1)break;
							if(dot[tx][ty]){flag=1;break;}
						}
						if(flag){
							while(1){
								tx-=nxt[d][0];ty-=nxt[d][1];
								if(tx>n||ty>m||tx<1||ty<1)break;
								if(tx==x&&ty==y)break;
								yline[tx][ty]=1;
							}
						}
					}
				}else yline[x][y]=0;
				break;
			case 1:
				dot[x][y]=0;
				for(int d=0;d<4;++d){
					tx=x,ty=y;
					bool flag=0;
					while(1){
						tx+=nxt[d][0];ty+=nxt[d][1];
						if(tx>n||ty>m||tx<1||ty<1)break;
						if(dot[tx][ty]){flag=1;break;}
					}
					if(flag){
						while(1){
							tx-=nxt[d][0];ty-=nxt[d][1];
							if(tx>n||ty>m||tx<1||ty<1)break;
							if(tx==x&&ty==y)break;
							((d<2)?xline[tx][ty]:yline[tx][ty])=0;
						}
					}
				}
				break;
		}
		ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(dot[i][j]||xline[i][j]||yline[i][j])ans++;
			}
		}
		mx=max(mx,ans);
	}
	cout<<mx<<'\n'<<ans;
}
