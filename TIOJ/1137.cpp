
TIOJ

    Bulletin
    Problems
    Submissions
    Contests
    Discuss
    About
    Rank
    kennyfs
    Sign out

校隊培訓簡報 連結都在這裡！
Results of submission #279050

Problem
Total Time (ms)
Max Memory (KiB)
Verdict
Score
1137. 4.收費站設置問題
28
5552
Accepted
100
Subtask Results
Subtask no. 	Testdata Range 	Score
1 	0 	100 / 100
Testdata Results
Testdata no. 	Subtasks 	Time (ms) 	Memory (KiB) 	Verdict 	Score
0 	1 	28 	5552 	Accepted 	100
Submitter:
kennyfs
Compiler:
c++14
Code Length:
1.24 KB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
using namespace std;
const int N=1e4+10;
int t,n,m,vis[N],low[N],cnt;
bool iscut[N];
vector<int> cut,G[N];
void dfs(int u,int fa=-1){
	vis[u]=low[u]=++cnt;
	int child=0;
	for(int v:G[u]){
        if(v==fa)continue;
        if(vis[v])low[u]=min(low[u],vis[v]);
        else{
            dfs(v,u);
            if(fa!=-1&&low[v]>=vis[u]&&!iscut[u])cut.pb(u),iscut[u]=1;
            ++child;low[u]=min(low[u],low[v]);
        }
	}
	if(fa==-1&&child>1)cut.pb(u),iscut[u]=1;
}
int main(){
    Hirasawa_Yui_My_Wife
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        cut.clear();
        memset(iscut,0,sizeof(iscut));
        memset(low,0,sizeof(low));
        cnt=0;
        while(m--){
            int u,v;
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        for(int i=1;i<=n;++i)if(!vis[i])dfs(i);
        for(int i=1;i<=n;++i)G[i].clear();
        sort(cut.begin(),cut.end());
        cout<<cut.size()<<'\n';
        if(cut.size()==0){cout<<"0\n";continue;}
        for(int i:cut)cout<<i<<' ';
        cout<<'\n';
    }
}
