#include <iostream>
#include <cstring>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e3+10;
int n,m;
char ch[N][N];
bool vis[N][N];
int nxt[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int x,int y){
    if(vis[x][y]||ch[x][y]=='#')return;
    vis[x][y]=1;
    for(int i=0;i<4;++i){
        int tx=x+nxt[i][0],ty=y+nxt[i][1];
        if(tx<0||tx>=n||ty<0||ty>=m)continue;
        dfs(tx,ty);
    }
}
int main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>m;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>ch[i][j];
    int total=0;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(!vis[i][j]&&ch[i][j]=='.')dfs(i,j),++total;
    cout<<total;
}
