#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=16;
int n,m,p;
int dp[2][1<<(N+1)];
void add(int& a,int b){
	a+=b;
	if(a>=p)a-=p;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>p;
	if(m>n)swap(n,m);//now m<=n
	int a=1,b=0;//always a to b
	fill(dp[0],dp[0]+(1<<(N+1)),1);
	fill(dp[1],dp[1]+(1<<(N+1)),0);
	for(int i=1;i<n;++i){
		//dp[0][j] are all 1
		for(int j=1;j<m;++j){
			//i,j are 0-based
			//for any i and s, dp[i][0][s]=dp[i][last][s]. Position 0 doesn't matter. If it's never valid(like s=xxx000), dp[i][1] will find it.
			swap(a,b);
			fill(dp[b],dp[b]+(1<<(N+1)),0);
			for(int s=0;s<1<<(m+1);++s){
				for(int w:{0,1}){
					if(w+!!(s>>(j-1)&1)+!!(s>>j&1)+!!(s>>(j+1)&1)>=2){
						int ns=s;
						if((s>>j&1)!=w)//if s>>j&1 != w, change s by s=s^(1<<j)
							ns^=1<<j;
						add(dp[b][ns],dp[a][s]);
					}
				}
			}
		}
		/*     x
		 * xxxxx
		 * to
		 * xxxxx
		 * x
		 * 
		 * xxxxx
		 * 0
		 * =
		 * xxxxx
		 * 1
		 * =
		 *     1
		 * xxxxx
		 * +
		 *     0
		 * xxxxx
		 * */
		swap(a,b);
		fill(dp[b],dp[b]+(1<<(N+1)),0);
		int full=(1<<(m+1))-1;
		for(int s=0;s<1<<(m+1);++s){
			add(dp[b][full&(s<<1)  ],dp[a][s]);
			add(dp[b][full&(s<<1|1)],dp[a][s]);
		}
	}
	int ans=0;
	for(int s=0;s<1<<m;++s){
		add(ans,dp[b][s<<1]);//dp[b][s<<1]=dp[b][s<<1|1] because I transform it at last.
	}
	cout<<ans<<'\n';
}
