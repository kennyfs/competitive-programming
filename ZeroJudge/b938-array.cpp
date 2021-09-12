#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e6+10;
int n,m;
int nxt[N];
bool dead[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=1;i<=n-1;++i){
		nxt[i]=i+1;
	}
	nxt[n]=0;
	int killer;
	for(int i=0;i<m;++i){
		cin>>killer;
		if(dead[killer]||nxt[killer]==0){
			cout<<"0u0 ...... ?\n";
			continue;
		}
		cout<<nxt[killer]<<'\n';
		dead[nxt[killer]]=1;
		nxt[killer]=nxt[nxt[killer]];
	}
}
//陣列的鏈結串列
