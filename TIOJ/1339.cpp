#include <iostream>
#include <utility>
#include <unordered_map>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int const N=1e6+10,mod=1e9+9;
int n;
pii d[N];
int y[N],bit[N],cnt[N];
unordered_map<int,int> mp;
inline void madd(int& a,int b){
	b%=mod;
	a+=b;
	if(a>=mod)a-=mod;
}
inline void add(int i,int v){
	for(;i<=n;i+=i&-i){
		madd(bit[i],v);
		++cnt[i];
	}
}
inline pii query(int i){
	int ans=0,ans2=0;
	for(;i;i-=i&-i){
		madd(ans,bit[i]);
		ans2+=cnt[i];
	}
	return {ans,ans2};
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>d[i].F>>d[i].S;
		y[i]=d[i].S;
	}
	sort(d,d+n);
	sort(y,y+n);
	int nn=unique(y,y+n)-y;
    for(int i=0;i<nn;i++){
        mp[y[i]]=i+1;
    }
    int ans=0;
    for(int i=0;i<n;++i){
		pii a=query(mp[d[i].S]);
		madd(ans,(1ll*d[i].F*d[i].S%mod*a.S%mod-a.F+mod)%mod);
		add(mp[d[i].S],1ll*d[i].F*d[i].S%mod);
	}
	cout<<ans<<'\n';
}
//噁心的BIT，數學
