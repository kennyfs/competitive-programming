#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const M=1e9+7;
struct matrix{
	int num[2][2];
	matrix(){}
	matrix(int a,int b,int c,int d){
		num[0][0]=a;num[0][1]=b;num[1][0]=c;num[1][1]=d;
	}
};
matrix mul(matrix a,matrix b){
	matrix ret;
	for(int i:{0,1}){
		for(int j:{0,1}){
			ret.num[i][j]=0;
			for(int k:{0,1}){
				ret.num[i][j]=(ret.num[i][j]+1ll*a.num[i][k]*b.num[k][j])%M;
			}
		}
	}
	return ret;
}
matrix fastpow(matrix a,int b){
	matrix ret(1,0,0,1);
	while(b){
		if(b&1){
			ret=mul(ret,a);
		}
		a=mul(a,a);
		b>>=1;
	}
	return ret;
}
int a,b,c,d,n;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>c>>d>>a>>b>>n;
	matrix T(b,a,1,0);
	matrix ans(d,0,c,0);
	ans=mul(fastpow(T,n-2),ans);
	cout<<ans.num[0][0];
}