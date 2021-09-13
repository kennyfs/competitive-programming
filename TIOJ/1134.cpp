#include <iostream>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int const N=200+10;
int t,n,m;
int a[N][N],pre[N][N],b[N];
pii frt[N];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			pre[i][0]=0;
			for(int j=1;j<=m;++j){
				cin>>a[i][j];
				a[i][j]=a[i][j]?-1:1;
				pre[i][j]=pre[i][j-1]+a[i][j];
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=i;++j){
				frt[0]={0,0};
				for(int k=1;k<=m;++k){
					frt[k]={frt[k-1].F+pre[j][k]-pre[i-1][k],k};
				}
				sort(frt+1,frt+m+1);
				int ind;
				ind=1;
				for(int k=2;k<=m;++k){
					if(frt[k].S>frt[ind].S)cout<<j-i+1<<' '<<frt[k].S-frt[ind].S+1<<'\n',ans=max(ans,(frt[k].S-frt[ind].S+1)*(j-i+1));
					if(frt[k].S<frt[ind].S)ind=k;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
