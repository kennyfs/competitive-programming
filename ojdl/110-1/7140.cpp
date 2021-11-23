#include <iostream>
using namespace std;
#define int long long
signed main(){
	int n,m;
	cin>>n>>m;
	if(n&1&&m&1)cout<<n*m-4;
	else cout<<n*m-3;
}
