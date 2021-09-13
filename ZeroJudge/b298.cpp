#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb emplace_back
using namespace std;
int const N=1e4+10;
int n,m,l,q;
bool vis[N];
vector<int> G[N];
void dfs(int x){
    if(vis[x])return;
    vis[x]=1;
    for(int v:G[x]){
        dfs(v);
    }
}
int main(){
	Hirasawa_Yui_My_Wife
    cin>>n>>m>>l>>q;
    int a,b;
    while(m--){
        cin>>a>>b;
        G[a].pb(b);
    }
    while(l--)cin>>a,dfs(a);
    while(q--){
        cin>>a;
        if(vis[a]){
            cout<<"TUIHUOOOOOO\n";
        }else{
            cout<<"YA~~\n";
        }
    }
}
