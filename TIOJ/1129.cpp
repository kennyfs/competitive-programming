#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define pb emplace_back
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=4e3+10;
int a,b,c,f[N],sz[N];
struct p{
    int x,y;
    int operator*(p a){
        return (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y);
    }
}P[N];
int fa(int me){
    if(f[me]==me)return me;
    return f[me]=fa(f[me]);
}
void join(int a,int b){
    int x=fa(a),y=fa(b);
    if(x==y)return;
    f[y]=x;
    sz[x]+=sz[y];
}
vector<int> ans;
int main(){
    Hirasawa_Yui_My_Wife
    int x,y;
    while(cin>>a>>b>>c){
        c=c*c;
        for(int i=1;i<=b;++i)f[i]=i,sz[i]=1;
        ans.clear();
        x=(269*a+11)%103;y=(271*a+13)%97;
        P[1]={x,y};
        for(int i=2;i<=b;++i){
            x=(269*x+11)%103;y=(271*y+13)%97;
            P[i]={x,y};
            for(int j=1;j<i;++j){
                if(P[i]*P[j]<=c)join(i,j);
            }
        }
        for(int i=1;i<=b;++i)if(i==fa(i))ans.pb(sz[i]);
        cout<<ans.size()<<'\n';
        sort(ans.begin(),ans.end());
        for(int i:ans)cout<<i<<' ';
        cout<<'\n';
    }
}
