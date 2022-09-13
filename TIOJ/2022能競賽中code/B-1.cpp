#include <iostream>
using namespace std;
#define int long long
#define wiwiho 5208e7
const int N=1500+520,inf=8e7*wiwiho;
int n,m,a[N][N],pre;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }
    //hen
    int mxi,imxs,imxt,imx=-inf;
    for(int i=1;i<=n;++i){
        pre=0;
        int premin=0,bs,bt,b=-inf,cur,mins=0;
        for(int j=1;j<=m;++j){
            pre+=a[i][j];
            cur=pre-premin;
            if(cur>b){
                bt=j;
                bs=mins+1;
                b=cur;
            }
            if(premin>pre)mins=j,premin=pre;
        }
        if(b>imx){
            mxi=i;
            imxs=bs;
            imxt=bt;
            imx=b;
        }
    }
    //jizz
    int mxj,jmxs,jmxt,jmx=-inf;
    for(int j=1;j<=m;++j){
        pre=0;
        int premin=0,bs,bt,b=-inf,cur,mins=0;
        for(int i=1;i<=n;++i){
            pre+=a[i][j];
            cur=pre-premin;
            if(cur>b){
                bt=j;
                bs=mins+1;
                b=cur;
            }
            if(premin>pre)mins=j,premin=pre;
        }
        if(b>jmx){
            mxj=j;
            jmxs=bs;
            jmxt=bt;
            jmx=b;
        }
    }
    cout<<mxi<<' '<<imxs<<' '<<imxt<<' '<<imx;
    if(imx>=jmx){
        //hen
        cout<<imx<<'\n';
        for(int i=1;i<mxi;++i)cout<<'U';
        for(int i=n;i>mxi;--i)cout<<'D';
        for(int j=1;j<imxs;++j)cout<<'L';
        for(int j=m;j>imxt;--j)cout<<'R';
        cout<<'D';
    }else{
        cout<<jmx<<'\n';
        for(int j=1;j<mxj;++j)cout<<'L';
        for(int j=m;j>mxj;--j)cout<<'R';
        for(int i=1;i<jmxs;++i)cout<<'U';
        for(int i=n;i>jmxt;--i)cout<<'D';
        cout<<'R';
    }
}
