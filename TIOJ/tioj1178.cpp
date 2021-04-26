#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
const int MAXN=100010;
int n;
pii data[MAXN];
vector<int> up(MAXN),dn(MAXN);
int upsz,dnsz;
int cross(int aa,int bb,int cc){
	pii a=data[aa],b=data[bb],c=data[cc];
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
main(){
	cin>>n;
	if(n<=3){cout<<n<<'\n';return 0;}
	int a,b;
	for(int i=0;i<n;++i){
		cin>>a>>b;
		data[i].x=a,data[i].y=b;
	}
	sort(data,data+n);
	up[0]=0;up[1]=1;
	dn[0]=0;dn[1]=1;
	upsz=2;
	dnsz=2;
	for(int i=2;i<n;++i){
		while(upsz>=2&&cross(up[upsz-2],up[upsz-1],i)>=0)
			--upsz;
		while(dnsz>=2&&cross(dn[dnsz-2],dn[dnsz-1],i)<=0)
			--dnsz;
		up[upsz++]=i;
		dn[dnsz++]=i;
	}
	cout<<upsz+dnsz-2<<'\n';
}
