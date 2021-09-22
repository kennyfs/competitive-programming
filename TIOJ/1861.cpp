#include <iostream>
#include <queue>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
int n;
ll tmp;
priority_queue<ll,vector<ll>,greater<ll>> pq;
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n){
		while(n--)cin>>tmp,pq.push(tmp);
		ll ans=0;
		while(pq.size()>1){
			ll a=pq.top();pq.pop();ll b=pq.top();pq.pop();
			ans+=a+b;
			pq.push(a+b);
		}
		cout<<ans<<'\n';
		pq.pop();
	}
}
