#include <iostream>
#define ll long long
using namespace std;
int const M=1e9+7;
ll c,d,e;
int a,b,n;
int main(){
	cin>>c>>d>>a>>b>>n;
	for(int i=2;i<n;++i){
		e=(c*a+d*b)%M;
		c=d;
		d=e;
	}
	cout<<d;
}