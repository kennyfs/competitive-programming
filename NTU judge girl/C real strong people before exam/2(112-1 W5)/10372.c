#include <stdio.h>
#define int long long
signed main(){
	int n,x[50156],y[50156],ans[50156],ind=0,mindis;
	scanf("%lld",&n);
	for(int i=0;i<=n;++i)scanf("%lld%lld",x+i,y+i);
	mindis=(x[n]-x[0])*(x[n]-x[0])+(y[n]-y[0])*(y[n]-y[0]);
	ans[ind++]=0;
	for(int i=1;i<n;++i){
		int dis=(x[n]-x[i])*(x[n]-x[i])+(y[n]-y[i])*(y[n]-y[i]);
		if(dis<mindis){
			mindis=dis;
			ind=0;
			ans[ind++]=i;
		}else if(dis==mindis){
			ans[ind++]=i;
		}
	}
	for(int i=0;i<ind;++i)
		printf("%lld\n",ans[i]);
}
