#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=310;
int n;
bool down[10],everdown[10];
int cd[10],a[N];
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i){//add i remove i-12
		if(i-12>=0&&a[i-12]!=-1)down[a[i-12]]=0;
		down[a[i]]=everdown[a[i]]=1;
		bool clear=1;
		for(int i=1;i<=9;++i){
			if(!down[i]){clear=0;break;}
		}
		if(clear){cout<<"perfect";return 0;}
	}
	int ans=0;
	for(int i=1;i<=9;++i){
		if(everdown[i])ans+=i;
	}
	cout<<ans;
}