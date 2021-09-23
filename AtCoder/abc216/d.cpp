#include <iostream>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=2e5+10;
int n,m,k,tmp;
queue<int> q[N],todo;
int quan[N];
pii d[N];
int main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>k;
        while(k--){
            cin>>tmp;
            if(!d[tmp].F)d[tmp].F=i;
            else d[tmp].S=i;
            q[i].push(tmp);
        }
        ++quan[q[i].front()];
    }
    for(int i=1;i<=n;++i)if(quan[i]==2)todo.push(i);
    int done=0;
    while(!todo.empty()){
        int frt=todo.front();todo.pop();
        ++done;
        quan[frt]=-8e7;
        q[d[frt].F].pop();
        q[d[frt].S].pop();
        if(!q[d[frt].F].empty()&&++quan[q[d[frt].F].front()]==2)todo.push(q[d[frt].F].front());
        if(!q[d[frt].S].empty()&&++quan[q[d[frt].S].front()]==2)todo.push(q[d[frt].S].front());
    }
    if(done==n)cout<<"Yes\n";
    else cout<<"No\n";
}
