#include <iostream>
#include <deque>
#include <stack>
#include <cmath>
#define pb push_back
#define pf push_front
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+10;
int n,q,K;
stack<int> tmp;
int main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>q;
    K=sqrt(n);
    deque<int> d[(n+q)/K+10];
    //1 to K-1,
    //K to 2K-1...
    d[0].pb(0);
    for(int i=1,a;i<=n;++i){
        cin>>a;
        d[i/K].pb(a);
    }
    string op;
    int i,x,a,b;
    while(q--){
        cin>>op;
        if(op=="ADD"){
            ++n;
            cin>>i>>x;
            a=i/K;b=i%K;
            for(int i=1;i<=b;++i)tmp.push(d[a].front()),d[a].pop_front();
            d[a].pf(x);
            while(!tmp.empty())d[a].pf(tmp.top()),tmp.pop();
            for(int i=a;d[i].size()==K+1;++i){
                d[i+1].pf(d[i].back());
                d[i].pop_back();
            }
        }
        if(op=="LEAVE"){
            --n;
            cin>>i;
            a=i/K;b=i%K;
            for(int i=1;i<=b;++i)tmp.push(d[a].front()),d[a].pop_front();
            d[a].pop_front();
            while(!tmp.empty())d[a].pf(tmp.top()),tmp.pop();
            for(int i=a;d[i+1].size();++i){
                d[i].pb(d[i+1].front());
                d[i+1].pop_front();
            }
        }
        if(op=="QUERY"){
            cin>>i;
            a=i/K;b=i%K;
            cout<<d[a][b]<<'\n';
        }
    }
}
