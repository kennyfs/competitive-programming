#include <iostream>
#include <utility>
#include <cstring>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e3+10;
int mp[N][N];
struct mv{
    int x,y,st;
    mv():x(0),y(0),st(0){}
    mv(int a,int b,int c):x(a),y(b),st(c){}
};
int n,m,p,q,a,b,gx,gy,ans;
int nxt[8][2],mi[N][N];
void dfs(int x,int y,int d){
    if(x==gx&&y==gy){ans=min(ans,d);return;}
    mi[x][y]=min(mi[x][y],d);
    for(int i=0;i<8;++i){
        int tx=x+nxt[i][0],ty=y+nxt[i][1];
        if(tx>n||tx<1||ty>m||ty<1||mp[tx][ty]||d+1>mi[tx][ty])continue;
        dfs(tx,ty,d+1);
    }
}
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>m>>p>>q>>a>>b;
    if(n==1&&m==1){cout<<"0\n";return 0;}
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>mp[i][j];
    nxt[0][0]=0;nxt[0][1]=q;
    nxt[1][0]=0;nxt[1][1]=-q;
    nxt[2][0]=q;nxt[2][1]=0;
    nxt[3][0]=-q;nxt[3][1]=0;
    nxt[4][0]=0;nxt[4][1]=p;
    nxt[5][0]=0;nxt[5][1]=-p;
    nxt[6][0]=p;nxt[6][1]=0;
    nxt[7][0]=-p;nxt[7][1]=0;
    //dfs
    fill(&mi[0][0],&mi[N-1][N-1],1e9);
    gx=n,gy=m,ans=1e9;
    dfs(1,1,0);
    fill(&mi[0][0],&mi[N-1][N-1],1e9);
    gx=n,gy=m;int fa=ans;
    dfs(a,b,fa);
    if(ans==1e9){cout<<"-1\n";return 0;}
    cout<<ans<<'\n';
}

