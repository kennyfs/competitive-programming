#include <iostream>
using namespace std;
const int N=2e3+10;
int n,cnt[101];
int main(){
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
