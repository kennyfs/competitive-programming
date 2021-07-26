#pragma GCC optimize(2)
#pragma GCC optimize("inline")
#include <iostream>
#include <vector>
#include <algorithm>
#define pb emplace_back
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e5+10;
int BIT[N];
int n;
vector<int> a(N),b;
void add(int i){
	for(;i<=n;i+=i&-i)
		++BIT[i];
}
int query(int i){
	int ret=0;
	for(;i;i^=i&-i)
		ret+=BIT[i];
	return ret;
}
inline int read(){
	int x=0;bool w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}
int main(){
	Hirasawa_Yui_My_Wife
	int t=1;
	ll ans;
	n=read();
	while(n){
		b.clear();
		for(register int i=0;i<n;++i)a[i]=read(),b.pb(a[i]);
		sort(b.begin(),b.end());
		b.erase(unique(b.begin(),b.end()),b.end());
		for(register int i=0;i<n;++i)
			a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
		fill(BIT,BIT+N,0);
		ans=0;
		for(register int i=0;i<n;++i){
			ans+=i-query(a[i]);
			add(a[i]);
		}
		cout<<"Case #"<<t++<<": "<<ans<<'\n';
		n=read();
	}
}
