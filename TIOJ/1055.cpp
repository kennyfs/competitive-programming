#include <iostream>
using namespace std;
short a,b;
signed main(){
	cin>>a>>b;
	if(a>b)for(short i=a;i>=b;--i){for(short j=0;j<i;++j)cout<<'*';cout<<'\n';}
	else for(short i=a;i<=b;++i){for(short j=0;j<i;++j)cout<<'*';cout<<'\n';}
}
