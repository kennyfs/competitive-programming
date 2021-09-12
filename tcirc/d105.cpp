#include <iostream>
#include <cstring>
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5+10,M=1e2+3;
int n,m;
int w[2*N],op[M],l[N],r[N];
void build(int cur){
	if(cur>=n)return;
	build(l[cur]);
	build(r[cur]);
	w[cur]=w[l[cur]]+w[r[cur]];
}
int put(int o){
	int cur=1;
	while(cur<n){
		w[cur]+=o;
		cur=(w[l[cur]]<=w[r[cur]])?l[cur]:r[cur];
	}
	w[cur]+=o;
	return cur;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=n;i<2*n;++i)cin>>w[i];
	for(int i=0;i<m;++i)cin>>op[i];
	int q,s,t;
	for(int i=0;i<n-1;++i)cin>>q>>s>>t,l[q]=s,r[q]=t;
	build(1);
	for(int i=0;i<m;++i){
		cout<<put(op[i])<<' ';
	}
	cout<<'\n';
}
//二分搜尋樹實作
