#include <iostream>
using namespace std;
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int const mod=3;
int n,c[3][3];
string s;
int C(int x,int y){
	if(x<3&&y<3)return c[x][y];
	return c[x%3][y%3]*C(x/3,y/3)%mod;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>s;
	int tmp;
	c[0][0]=1;
    for(int i=1;i<3;++ i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    int ans=0;
	for(int i=0;i<n;++i){
		switch(s[i]){
			case 'W':
				tmp=0;
				break;
			case 'B':
				tmp=1;
				break;
			case 'R':
				tmp=2;
				break;
		}
		ans+=tmp*C(n-1,i);
		ans%=mod;
	}
	if(!(n&1))ans=(-ans+mod)%mod;
	switch(ans){
		case 0:
			cout<<"W\n";
			break;
		case 1:
			cout<<"B\n";
			break;
		case 2:
			cout<<"R\n";
			break;
	}
}
