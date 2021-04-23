#include <iostream>
#include <algorithm>
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
	int n;cin>>n;
	ll l[n][2],dpa[2],dpb[2],dpn[2];
	for(int t=0;t<2;++t)
		for(int i=0;i<n;++i)
			cin>>l[i][t];
	int a=0,b=1;
	fill(dpa,dpa+2,0),fill(dpb,dpb+2,0),fill(dpn,dpn+2,0);
	for(int i=0;i<n;++i){
		dpa[a]=max(dpb[b],dpn[b])+l[i][0];
		dpb[a]=max(dpa[b],dpn[b])+l[i][1];
		dpn[a]=max(dpa[b],dpb[b]);
		swap(a,b);
	}
	cout<<max(max(dpa[b],dpb[b]),dpn[b])<<'\n';
}
