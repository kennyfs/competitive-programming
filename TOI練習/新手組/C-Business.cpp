#include <iostream>
#include <cstring>
using namespace std;
const int N=3e1+10,D=1e2+10,S=9e4+10;
int n,a[N],add[N];
int main(){
	int ind=1;
	while(cin>>a[ind]&&a[ind++]);
	n=ind-2;
	if(n==1){cout<<a[1];return 0;}
	int day;
	cin>>day;
	while(day--){
		memset(add,0,sizeof(add));
		for(int i=2;i<=n-1;++i){
			if(a[i]>a[i-1])add[i-1]+=a[i]/20;
			if(a[i]>a[i+1])add[i+1]+=a[i]/20;
		}
		if(a[1]>a[2])add[2]+=a[1]/10;
		if(a[n]>a[n-1])add[n-1]+=a[n]/10;
		for(int i=1;i<=n;++i){
			a[i]+=add[i];
		}
	}
	for(int i=1;i<=n;++i)cout<<a[i]<<' ';
}
