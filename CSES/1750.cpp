#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2e5+10;
int n,q,nxt[N][32];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>nxt[i][0];
	for(int i=1;i<=31;++i){
		for(int x=1;x<=n;++x){
			nxt[x][i]=nxt[nxt[x][i-1]][i-1];
		}
	}
	while(q--){
		int x,k,p=0;
		cin>>x>>k;
		while(k){
			if(k&1)x=nxt[x][p];
			k>>=1;p++;
		}
		cout<<x<<'\n';
	}
}
