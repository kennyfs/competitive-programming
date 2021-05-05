#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=10005,NUM=1<<24,lgNUM=24;
int n;
short dp[NUM][2];
string s;
int count(int n){
	int ans=0;
	for(int i=0;i<24;++i)if(n&(1<<i))++ans;
	return ans;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s;
		int ind=0;
		for(int j=0;j<3;++j)ind=(ind|1<<(s[j]-'a'));
		int sub=ind;
		do{
			switch(count(sub)){
				case 1:
					dp[sub][0]++;break;
				case 2:
					dp[sub][0]--;break;
				case 3:
					dp[sub][0]++;break;
			}
			sub=(sub-1)&ind;
		}while(sub!=ind);
	}
	int a=0,b=1;
	for(int j=1;j<=lgNUM;++j){//last j bits can be different
		swap(a,b);
		for(int i=0;i<NUM;++i){
			dp[i][a]=dp[i][b];
			if(i&(1<<(j-1)))
				dp[i][a]+=dp[i-(1<<(j-1))][b];
		}
	}
	int ans=0;
	for(int i=0;i<NUM;++i){
		ans^=(dp[i][a]*dp[i][a]);
	}
	cout<<ans<<'\n';
}
