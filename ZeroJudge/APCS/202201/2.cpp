#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int N=1e3+10;
int n,m,s[N],t[N],p[N][2],lose[N];
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=1;i<=n;++i)cin>>t[i];
	for(int i=1;i<=n;++i)cin>>p[i][0];
	int now=1,nxt=0,len=n;
	while(len>1){
		swap(now,nxt);
		int loser=(len+1>>1)+1;
		for(int i=1;i+1<=len;i+=2){
			int fir=p[i][now],sec=p[i+1][now];
			int a=s[fir],b=t[fir],c=s[sec],d=t[sec];
			if(a*b<c*d)swap(fir,sec),swap(a,c),swap(b,d);
			s[fir]=a+c*d/(2*b);
			t[fir]=b+c*d/(2*a);
			s[sec]=c+c/2;
			t[sec]=d+d/2;
			p[i+1>>1][nxt]=fir;
			if(++lose[sec]<m)p[loser++][nxt]=sec;
		}
		if(len&1)p[(len>>1)+1][nxt]=p[len][now];
		len=loser-1;
	}
	cout<<p[1][nxt];
}
