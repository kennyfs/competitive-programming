#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=5e3+10;
int prime[N],stk;
int main(){
	stk=0;
	for(int i=2;i<N;++i){
		bool flag=1;
		for(int j=0;j<stk;++j){
			if(i%prime[j]==0){flag=0;break;}
		}
		if(flag)prime[stk++]=i;
	}
	int n;
	while(cin>>n){
		cout<<"primes between 1 ~ "<<n<<':';
		for(int i=0;i<stk&&prime[i]<=n;++i){
			cout<<' '<<prime[i];
		}
		cout<<'\n';
	}
}
//質數，O(n^2)
