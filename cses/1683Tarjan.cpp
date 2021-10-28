#include <iostream>
#include <vector>
#include <stack>
#define steak stack
#define pb emplace_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5+10;
int n,m,tot=0,scctot=1,vis[N],low[N],team[N];
vector<int> G[N];
bool insteak[N];
steak<int> stk;
void dfs(int cur){
    vis[cur]=low[cur]=++tot;
    stk.push(cur);
    insteak[cur]=1;
    for(int nxt:G[cur]){
        if(!vis[nxt])dfs(nxt);
        if(insteak[nxt]){
            low[cur]=min(low[cur],low[nxt]);
        }
    }
    if(low[cur]==vis[cur]){
        int j;
        do{
            j=stk.top();stk.pop();
            insteak[j]=0;
            team[j]=scctot;
        }while(j!=cur);
        ++scctot;
    }
}
int main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
    }
    for(int i=1;i<=n;++i){
        if(!vis[i])dfs(i);
    }
    cout<<--scctot<<'\n';
    for(int i=1;i<=n;++i)cout<<team[i]<<' ';
	cout<<'\n';
}
