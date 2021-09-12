#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=3000+10;
int n,tmp1,tmp2;
struct dot{
	int x,y;
	int operator*(dot& o){
		tmp1=o.x-x;tmp2=o.y-y;
		return tmp1*tmp1+tmp2*tmp2;
	}
}dots[N];
istream& operator>>(istream& s,dot& a){
	s>>a.x>>a.y;
	return s;
}
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n&&n){
		for(int i=0;i<n;++i)cin>>dots[i];
		int ma=-(1<<30);
		int ba,bb;
		for(int a=n-1;a>=0;--a){//a<b
			for(int b=n-1;b>a;--b){
				tmp1=dots[a]*dots[b];
				if(tmp1>=ma){
					ma=tmp1;
					ba=a;bb=b;
				}
			}
		}
		cout<<ba<<' '<<bb<<'\n';
	}
}
//暴力
