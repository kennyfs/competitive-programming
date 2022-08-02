#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int const N=5e2+10;
int n;
long double num[N];
int sol[N];
vector<long double> para[N];
//para[i][j]: i-th line, j-th parameter
signed main(){
    cin>>n;
    for(int i=1;i<=n;++i){
		para[i].resize(N);
        for(int j=1;j<=n;++j){
            cin>>para[i][j];
        }
        cin>>num[i];
    }
    for(int i=1;i<=n;++i){
		/*for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k)cout<<para[j][k]<<' ';
			cout<<num[j]<<'\n';
		}
		cout<<'\n';*/
        int nonzero=-1;
        for(int j=i;j<=n;++j)if(para[j][i]!=0){nonzero=j;break;}
        if(nonzero==-1)continue;
        if(nonzero>i)swap(para[i],para[nonzero]),swap(num[i],num[nonzero]);
        for(int j=i+1;j<=n;++j){
            if(abs(para[j][i])<1e-5){para[j][i]=0;continue;}
            long double mul=para[j][i]/para[i][i];
            for(int k=1;k<=n;++k){
				para[j][k]-=para[i][k]*mul;
				if(abs(para[j][k])<1e-5)para[j][k]=0;
			}
            num[j]-=num[i]*mul;
        }
    }
    bool no=0;
    for(int i=n;i>=1;--i){//消第i行，算出第i個未知數
		for(int k=i+1;k<=n;++k){
			if(sol[k]==8e7&&abs(para[i][k])>1e-5){sol[i]=8e7;break;}
			num[i]-=sol[k]*para[i][k];
			para[i][k]=0;
		}
		if(sol[i]==8e7)continue;
		if(abs(para[i][i])>1e-5){
			sol[i]=num[i]/para[i][i];
			sol[i]=(int)(sol[i] + 0.5 - (sol[i]<0));
		}
		else sol[i]=8e7;
	}
	for(int i=1;i<=n;++i){
        cout<<i<<' ';
		if(sol[i]!=8e7)
			//cout<<fixed<<setprecision(3)<<sol[i]<<'\n';
            cout<<sol[i]<<'\n';
		else
			cout<<"Hirasawa Yui So Cute\n";
	}
}
