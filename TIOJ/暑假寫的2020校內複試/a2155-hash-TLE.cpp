#pragma Ofast
#pragma loop-opt(on)
#pragma GCC target("avx2")
#include <iostream>
#include <map>
#include <utility>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=3500+10;
ll const P=257,M=1125899839733759;
ll myhash[N][N];
map<ll,int> cnt[N];
string ss[N];
int n;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	if(n==1){
		cin>>ss[0];
		cout<<ss[0]<<'\n';
		return 0;
	}
	if(n>3500){cout<<"7122\n";return 0;}
	ll h=0;
	pair<int,int> mi={10000,0};
	for(int i=0;i<n;++i){
		cin>>ss[i];
		mi=min(mi,{ss[i].size(),i});
	}
	for(int i=0;i<n;++i){
		for(size_t st=0;st<ss[i].size();++st){
			h=0;
			for(size_t cur=st;cur<ss[i].size();++cur){
				h=((h*P)%M+ss[i][cur])%M;
				++cnt[i][h];
				if(i==mi.S)myhash[st][cur]=h;
			}
		}
	}
	bool bigflag=0;
	for(size_t st=0;st<ss[mi.S].size();++st){
		for(size_t ed=st;ed<ss[mi.S].size();++ed){
			h=myhash[st][ed];
			if(cnt[mi.S][h]!=1)continue;
			bool flag=1;
			for(int i=0;i<n;++i){
				if(i==mi.S)continue;
				if(cnt[i][h]!=1){flag=0;break;}
			}
			if(flag){cout<<ss[mi.S].substr(st,ed-st+1)<<'\n';bigflag=1;break;}
		}
		if(bigflag)break;
	}
	if(!bigflag)cout<<"7122\n";
}
