#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define pb emplace_back
using namespace std;
const int N=40;
int t,n,m,scccnt=1,scc[N];
vector<int> G[N],R[N];
stack<int> out;
bool vis[N];
void add(int a,int b){
    G[a^1].pb(b);
    G[b^1].pb(a);
    R[a].pb(b^1);
    R[b].pb(a^1);
}
void dfs(int cur){
    vis[cur]=1;
    for(int nxt:G[cur])if(!vis[nxt])dfs(nxt);
    out.push(cur);
}
void back_dfs(int cur){
    scc[cur]=scccnt;
    for(int nxt:R[cur])if(!scc[nxt])back_dfs(nxt);
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<N;++i)G[i].clear(),R[i].clear();
        while(!out.empty())out.pop();
        char c1,c2;
        int a1,a2;
        while(m--){
            cin>>c1>>a1>>c2>>a2;
            a1<<=1;a2<<=1;
            if(c1=='m')a1|=1;
            if(c2=='m')a2|=1;
            add(a1,a2);
        }
        memset(vis,0,sizeof(vis));
        memset(scc,0,sizeof(scc));
        for(int i=2;i<=2*n+1;++i){
            if(!vis[i])dfs(i);
        }
        while(!out.empty()){
            int top=out.top();out.pop();
            if(scc[top])continue;
            back_dfs(top);
            scccnt++;
        }
        bool ok=1;
        for(int i=2;i<=2*n;i+=2){
            if(scc[i]==scc[i|1]){ok=0;break;}
        }
        if(ok)cout<<"GOOD\n";
        else cout<<"BAD\n";
    }
}
