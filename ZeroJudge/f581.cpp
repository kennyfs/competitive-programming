#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=2e5+5,M=2e4+5;
int n,m;
int p[2*N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>p[i],p[i+n]=p[i];
	for(int i=1;i<2*n;++i)p[i]+=p[i-1];
	int s=0;
	for(int i=0,q;i<m;++i){
		cin>>q;
		if(s-1>=0)q+=p[s-1];
		s=lower_bound(&p[0],&p[2*n],q)-&p[0]+1;
		if(s>=n)s-=n;
	}
	cout<<s<<'\n';
}
