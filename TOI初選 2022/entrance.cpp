#include <iostream>
#include <utility>
#include <map>
#define pii pair<int,int>
#define F first
#define S second
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=2.5e3+10,R=12;
int n,r,r2,cnt;
map<pii,bool> mp;
int main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>r;
    r2=r*r;
    for(int i=1,x,y;i<=n;++i){
        cin>>x>>y;
        for(int dx=-R;dx<=R;++dx){
            for(int dy=-R;dy<=R;++dy){
                if(dx*dx+dy*dy<=r2){
                    if(mp.find({x+dx,y+dy})!=mp.end()){
                        mp[{x+dx,y+dy}]^=1;
                        if(mp[{x+dx,y+dy}])cnt++;
                        else cnt--;
                    }else{
                        mp[{x+dx,y+dy}]=1;
                        cnt++;
                    }
                }
            }
        }
    }
    cout<<cnt;
}
