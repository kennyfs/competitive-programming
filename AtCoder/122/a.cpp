#include <iostream>
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll const mod=1e9+7;
int n;
ll dpm[2],dpp[2];
ll dpmp[2],dppp[2];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	int tmp,a=1,b=0;
	if(n==1){
		cin>>tmp;
		cout<<tmp<<'\n';
		return 0;
	}
	if(n==2){
		cin>>a;
		cout<<(a*2)%mod<<'\n';
		return 0;
	}
	n-=2;
	cin>>dpp[0];
	cin>>tmp;
	dpm[0]=dpp[0]-tmp;
	dpp[0]+=tmp;
	dpmp[0]=1;dppp[0]=2;
	for(int i=1;i<=n;++i){
		cin>>tmp;
		swap(a,b);
		dpm[b]=(dpp[a]-tmp*dpmp[a]%mod)%mod;
		dpp[b]=((dpm[a]+dpp[a])%mod+tmp*dppp[a]%mod)%mod;
		dpmp[b]=dppp[a];
		dppp[b]=(dpmp[a]+dppp[a])%mod;
	}
	cout<<((dpm[b]+dpp[b])%mod+mod)%mod<<'\n';
}
