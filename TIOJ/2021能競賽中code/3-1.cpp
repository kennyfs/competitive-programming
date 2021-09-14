#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
#define pii pair<int,int>
#define F first
#define S second
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e3+10;
bool mp[N][N],vis[N][N];
struct mv{
    int x,y,st;
    mv():x(0),y(0),st(0){}
    mv(int a,int b,int c):x(a),y(b),st(c){}
};
int n,m,p,q,a,b;
int nxt[8][2];
signed main(){
    Hirasawa_Yui_My_Wife
    queue<mv> que;
    cin>>n>>m>>p>>q>>a>>b;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>mp[i][j];
    nxt[0][0]=0;nxt[0][1]=q;
    nxt[1][0]=0;nxt[1][1]=-q;
    nxt[2][0]=q;nxt[2][1]=0;
    nxt[3][0]=-q;nxt[3][1]=0;
    nxt[4][0]=0;nxt[4][1]=p;
    nxt[5][0]=0;nxt[5][1]=-p;
    nxt[6][0]=p;nxt[6][1]=0;
    nxt[7][0]=-p;nxt[7][1]=0;
    //bfs
    que.push(mv(1,1,0));
    bool flag=0;int ans;
    while(!que.empty()){
        mv t=que.front();que.pop();
        for(int i=0;i<8;++i){
            int tx=t.x+nxt[i][0],ty=t.y+nxt[i][1];
            if(tx>n||tx<1||ty>n||ty<1||mp[tx][ty]||vis[tx][ty])continue;
            vis[tx][ty]=1;
            if(tx==a&&ty==b){flag=1;ans=t.st+1;break;}
            que.push(mv(tx,ty,t.st+1));
        }
        if(flag)break;
    }
    memset(vis,0,sizeof(vis));
    queue<mv> q;
    q.push(mv(a,b,ans));
    flag=0;
    while(!q.empty()){
        mv t=q.front();q.pop();
        for(int i=0;i<8;++i){
            int tx=t.x+nxt[i][0],ty=t.y+nxt[i][1];
            if(tx>n||tx<1||ty>n||ty<1||mp[tx][ty]||vis[tx][ty])continue;
            vis[tx][ty]=1;
            if(tx==n&&ty==m){flag=1;ans=t.st+1;break;}
            q.push(mv(tx,ty,t.st+1));
        }
        if(flag)break;
    }
    if(!flag){cout<<"-1\n";return 0;}
    cout<<ans<<'\n';
}

