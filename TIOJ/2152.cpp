#include <iostream>
#include <cmath>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mid (l+r)>>1
using namespace std;
int const N=6666+10,OP=2e5+N+10;
int n,k,a[N],b[N],opcnt,ind[OP],tmp[N],app[N];
char op[OP];
inline bool cmp(int i,int j){
	return app[i]<app[j];
}
void dq(int l,int r){//b[l,r) must be in a[1,r-l+1)
	if(l+1==r){
		op[opcnt++]='T';
		op[opcnt++]='U';
		op[opcnt]='P';
		ind[opcnt++]=a[1];
		return;
	}
	dq(l,mid);
	for(int i=1;i<=r-l;++i){
		op[opcnt++]='T';
		tmp[i]=a[i];
	}
	fill(app,app+N,N);
	for(int i=mid;i<r;++i)app[b[i]]=min(app[b[i]],i);
	sort(tmp+1,tmp+r-l+1,cmp);
	tmp[r-l+1]=N;
	int p=r-l;
	for(int i=r-l;i;--i){
		if(tmp[i]==tmp[i+1]){
			op[opcnt]='P';
			a[p--]=ind[opcnt++]=tmp[i];
		}
	}
	for(int i=r-l;i;--i){
		if(tmp[i]!=tmp[i+1]){
			op[opcnt]='P';
			a[p--]=ind[opcnt++]=tmp[i];
		}
	}
	dq(mid,r);
}
int main(){
    //Hirasawa_Yui_My_Wife
    opcnt=0;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    fill(app,app+N,N);
    for(int i=1;i<=n;++i)app[b[i]]=min(app[b[i]],i),tmp[i]=a[i],op[opcnt++]='T';
    sort(tmp+1,tmp+n+1,cmp);
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
    dq(1,n+1);
    cout<<((opcnt-n)>>1)<<'\n';
    for(int i=0;i<opcnt;++i){
        cout<<op[i];
        if(op[i]=='P')cout<<' '<<ind[i];
        cout<<'\n';
    }
}
