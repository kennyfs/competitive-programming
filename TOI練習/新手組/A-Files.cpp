#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2e3+10;
int n,cnt[101];
int main(){
    Hirasawa_Yui_My_Wife
	cin>>n;
	int a;
	while(n--){
		cin>>a;
		cnt[(a/10)%100]++;
	}
	for(int i=0;i<=99;++i){
		if(cnt[i])cout<<i<<' '<<cnt[i]<<'\n';
	}
}
