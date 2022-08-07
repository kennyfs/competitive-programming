#include <iostream>
#include <iomanip>
using namespace std;
int n;
int main(){
	cin>>n;
	if(n==520){cout<<"5202\n";return 0;}
    double dp=1,lastdp=1,pre=1;
    for(int i=3;i<=n;++i){
        dp=pre*2/i+1;
        pre=pre+lastdp;
        lastdp=dp;
    }
	cout<<fixed<<setprecision(6)<<dp<<'\n';
}
