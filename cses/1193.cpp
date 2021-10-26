#include <iostream>
#include <stack>
using namespace std;
int const N=1e3+10;
int n,m;
int sx,sy,ex,ey;
bool vis[N][N];
char ch[N][N];
stack<int> stk;
int nxt[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
bool dfs(int x,int y){
    if(vis[x][y]||ch[x][y]=='#')return 0;
    vis[x][y]=1;
    if(ch[x][y]=='B')return 1;
    for(int i=0;i<4;++i){
        int tx=x+nxt[i][0],ty=y+nxt[i][1];
        if(tx<0||tx>=n||ty<0||ty>=m)continue;
        if(dfs(tx,ty)){
            stk.push(i);
            return 1;
        }
    }
    return 0;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){cin>>ch[i][j];if(ch[i][j]=='A')sx=i,sy=j;}
    dfs(sx,sy);
}
