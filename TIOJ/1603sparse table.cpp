#include <iostream>
#define int long long
#define INF 8e7*25;
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+10;
int n,q,smin[N][20],smax[N][20],po[20];//log_2 1e5=16.x
signed main(){
    Hirasawa_Yui_My_Wife
    po[0]=1;
    for(int i=1;i<20;++i){
        po[i]=po[i-1]<<1;
    }
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>smin[i][0];
        smax[i][0]=smin[i][0];
    }
    for(int j=1;j<=17;++j){
        for(int i=1;i<=n;++i){
            smax[i][j]=smax[i][j-1];
            smin[i][j]=smin[i][j-1];
            if(i+po[j-1]<=n){
                smax[i][j]=max(smax[i][j],smax[i+po[j-1]][j-1]);
                smin[i][j]=min(smin[i][j],smin[i+po[j-1]][j-1]);
            }
        }
    }
    int l,r,lg;
    int mi=INF;
    int ma=0;
    while(q--){
        cin>>l>>r;
        lg=__lg(r-l+1);
        //min
        mi=smin[l][lg];
        ma=smax[l][lg];
        //max
        mi=min(mi,smin[r-po[lg]+1][lg]);
        ma=max(ma,smax[r-po[lg]+1][lg]);
        cout<<ma-mi<<'\n';
    }
}
