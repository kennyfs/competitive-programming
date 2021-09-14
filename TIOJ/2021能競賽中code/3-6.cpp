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
    //bfs
    bool flag=0;int ans=0;
    if(a!=1||b!=1){
        que.push(mv(1,1,0));
        vis[1][1]=1;
        while(!que.empty()){
            mv t=que.front();que.pop();
            if(t.x==a&&t.y==b){flag=1;ans=t.st;break;}
            for(int i=0;i<8;++i){
                int tx=t.x+nxt[i][0],ty=t.y+nxt[i][1];
                if(tx>n||tx<1||ty>m||ty<1||mp[tx][ty]||vis[tx][ty])continue;
                vis[tx][ty]=1;
                que.push(mv(tx,ty,t.st+1));
            }
            if(flag)break;
        }
        if(!flag){cout<<"-1\n";return 0;}
    }
    memset(vis,0,sizeof(vis));
    queue<mv> q;
    flag=0;
    q.push(mv(a,b,ans));
    vis[a][b]=1;
    int fans=-1;
    while(!q.empty()){
        mv t=q.front();q.pop();
        //cout<<t.st<<' '<<t.x<<' '<<t.y<<'\n';
        if(t.x==n&&t.y==m){flag=1;fans=t.st;break;}
        for(int i=0;i<8;++i){
            int tx=t.x+nxt[i][0],ty=t.y+nxt[i][1];
            if(tx>n||tx<1||ty>m||ty<1||mp[tx][ty]||vis[tx][ty])continue;
            vis[tx][ty]=1;
            q.push(mv(tx,ty,t.st+1));
        }
        if(flag)break;
    }
    cout<<fans<<'\n';
}

