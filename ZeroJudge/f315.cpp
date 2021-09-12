#include <iostream>
#include <cstring>
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=2e5+10;
int n,a[N],st[N/2],ed[N/2];
int bit[N];
void add1(int pos){
	for(;pos<=2*n;pos+=pos&-pos){
		++bit[pos];
	}
}
int query(int pos){
	int ans=0;
	for(;pos;pos-=pos&-pos){
		ans+=bit[pos];
	}
	return ans;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	memset(st,0,sizeof(st));
	memset(ed,0,sizeof(ed));
	for(int i=1;i<=2*n;++i){
		cin>>a[i];
		if(st[a[i]])ed[a[i]]=i;
		else st[a[i]]=i;
	}
	add1(st[1]);
	add1(ed[1]);
	ll ans=0;
	for(int i=2;i<=n;++i){
		ans+=query(ed[i])-query(st[i]);
		add1(st[i]);
		add1(ed[i]);
	}
	cout<<ans<<'\n';
}
//BIT維護前綴
