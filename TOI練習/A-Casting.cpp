#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
const int N=20;
int n;
struct edge{
    int s,t;
};
vector<edge> E;
int main(){
    cin>>n;
    int a;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>a;
            if(a){
                E.pb({i,j});
            }
        }
    }
    int ans=0;
    for(int s=0;s<(1<<n);++s){
        int cnt=__builtin_popcount(s);
        bool flag=1;
        for(auto [u,v]:E){
            if((s&(1<<u))&&(s&(1<<v))){flag=0;break;}
        }
        if(flag)ans=max(ans,cnt);
    }
    cout<<ans;
}
