#include <iostream>
#include <cmath>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=6666+10,OP=1e5+10;
int n,k,a[N],b[N],opcnt,ind[OP],tmp[N],app[N];
char op[OP];
int main(){
    //Hirasawa_Yui_My_Wife
    opcnt=0;
    cin>>n;
    k=sqrt(n);
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    fill(app,app+N,N);
    for(int i=1;i<=n;++i)app[b[i]]=min(app[b[i]],i),tmp[i]=a[i],op[opcnt++]='T';
    sort(tmp+1,tmp+n+1,[&](int i,int j){
            return app[i]<app[j];
    });
    int p=n;
    tmp[n+1]=N;
    for(int i=n;i;--i){
        if(tmp[i]==tmp[i+1]){
            op[opcnt]='P';
            a[p--]=ind[opcnt++]=tmp[i];
        }
    }
    for(int i=n;i;--i){
        if(tmp[i]!=tmp[i+1]){
            op[opcnt]='P';
            a[p--]=ind[opcnt++]=tmp[i];
        }
    }
    for(int i=1;i<=n;i+=k){//do b[i,min(n,i+k)], require things must be in a[1,j]
        int j=min(n,i+k);
        //take [1,j] and put [1,i-1] then [i,j]
        for(int l=1;l<=j;++l)op[opcnt++]='T',tmp[i]=a[i];
        fill(app,app+N,N);//O(n^2) is fine
        for(int i=i;i<=j;++i)app[b[i]]=min(app[b[i]],i);
        sort(tmp+1,tmp+n+1,[&](int i,int j){
            return app[i]<app[j];
        });
        tmp[j+1]=N;
        p=j
        for(int l=j;l;--l){
            if(tmp[l]==tmp[l+1]){
                op[opcnt]='P';
                a[p--]=ind[opcnt++]=tmp[l];
            }
        }
        for(int l=j;l;--l){
            if(tmp[l]!=tmp[l+1]){
                op[opcnt]='P';
                a[p--]=ind[opcnt++]=tmp[l];
            }
        }
        //required b[i,j] are in the front

        for(int l=1;l<=i;++l)op[opcnt]='P',ind[opcnt++]=a[l];

    }
    cout<<((opcnt-n)>>1)<<'\n';
    for(int i=0;i<opcnt;++i){
        cout<<op[i];
        if(op[i]=='P')cout<<' '<<ind[i];
        cout<<'\n';
    }
}
