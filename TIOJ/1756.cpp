#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=100010;
int n,m;
int stack[N],stk=0;
int main(){
	Hirasawa_Yui_My_Wife
	while(cin>>n>>m){
		int last=0,tmp,ans=0,shoot;
		stk=0;
		for(int i=1;i<=n;++i){
			shoot=1;last=0;
			for(int j=1;j<=m;++j){
				cin>>tmp;
				if(tmp<last)++shoot;
				last=tmp;
			}
			bool flag=0;
			while(stack[stk]>shoot){--stk;flag=1;}
			if(!flag)ans+=shoot-stack[stk];
			stack[++stk]=shoot;
		}
		cout<<ans<<endl;
	}
}
//自以為是的唬爛解，WA，待解決
