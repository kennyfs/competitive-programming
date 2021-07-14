#include <iostream>
#include <algorithm>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int t,n,a[100010],cnt[100010][2];//cnt[i][j] means the number of i in odd(1) or even(0) index
int main(){
	Hirasawa_Yui_My_Wife
	cin>>t;
	while(t--){
		cin>>n;
		fill(&cnt[0][0],&cnt[100009][1]+1,0);
		for(int i=0;i<n;++i)cin>>a[i],++cnt[a[i]][i&1];
		sort(a,a+n);
		bool flag=1;
		for(int i=0;i<n;++i){
			if(!cnt[a[i]][i&1]){
				cout<<"nO\n";
				flag=0;
				break;
			}else{
				--cnt[a[i]][i&1];
			}
		}
		if(flag)cout<<"YeS\n";
	}
}
