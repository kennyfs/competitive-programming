#include <iostream>
using namespace std;
const int N=9+5;
int r,c,a[N][N],b[N][N];
int main(){
    cin>>r>>c;
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j){
            cin>>a[i][j];b[i][j]=a[i][j];
        }
    }
    int nxt[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j){
            int tot=0,cnt=0;
            if(!a[i][j]){
                for(auto [dx,dy]:nxt){
                    int tx=i+dx,ty=j+dy;
                    if(tx>r||tx<1||ty>c||ty<1)continue;
                    if(!a[tx][ty])continue;
                    cnt++;
                    tot+=a[tx][ty];
                }
                if(cnt){
                    b[i][j]=tot/cnt;
                }
            }
        }
    }
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j){
            cout<<b[i][j]<<' ';
        }
        cout<<'\n';
    }
}
