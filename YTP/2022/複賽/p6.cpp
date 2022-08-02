#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define A first
#define B second
#define pb push_back
const int N=1e3+10;
pii dot[N];
vector<int> G[N];
int dis[N];
bool by(pii i,pii j){
    int a=i.A-j.A,b=i.B-j.B;
    if(a==0&&abs(b)==1)return true;//BE
    if(b==0&&abs(a)==1)return true;//AD
    if(a*b==-1&&(a==1||a==-1))return true;
    return false;
}
void test(){
    cout<<by({1,0},{0,2})<<'\n';
}
int main(){
    //test();
    //return 0;
    int t=0,a=0,b=0;
    //cin>>t;
    char c;
    dot[0]={0,0};
    while(cin>>c){
        //cin>>c;
        switch(c){
        case 'A':
            a++;
            break;
        case 'B':
            b++;
            break;
        case 'C':
            a--;b++;
            break;
        case 'D':
            a--;
            break;
        case 'E':
            b--;
            break;
        case 'F':
            a++;b--;
            break;
        }
        t++;
        dot[t]={a,b};
        for(int i=0;i<t;++i){
            if(by(dot[i],dot[t])){
                G[i].pb(t);
                G[t].pb(i);
            }
        }
    }
    //for(int i=0;i<=t;++i){
    //    cout<<dot[i].A<<' '<<dot[i].B<<'\n';
    //}
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    pq.push({0,0});
    for(int i=1;i<=t;++i)dis[i]=8e7;
    while(!pq.empty()){
        auto [d,i]=pq.top();pq.pop();
        for(auto v:G[i]){
            if(dis[v]>d+1){
                dis[v]=d+1;
                pq.push({dis[v],v});
            }
        }
    }
    cout<<dis[t];
}
//AC
