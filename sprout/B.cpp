#include <iostream>
#define int long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,m,q;
signed main(){
    Hirasawa_Yui_My_Wife
    cin>>n>>m>>q;
    int ans=0,sx,sy,ex,ey,x,y;
    while(q--){
        cin>>sx>>sy>>ex>>ey>>x>>y;
        if(sx==ex&&sy==ey||((sx==x||sy==y)&&(ex==x||ey==y))){++ans;continue;}
    }
    cout<<ans;
}
