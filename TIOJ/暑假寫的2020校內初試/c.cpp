#include <iostream>
#include <bitset>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=16;
int n,m,k=1e9;
int dp[1<<N][2];
void add(int& a,int b){
	a+=b;
	if(a>k)a-=k;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>k;
	if(n<m)swap(n,m);
	int a=0,b=1;
	int sum[15],tmp[15];
	int t,pos;
	bool flag;
	std::bitset<16> out;
	for(int i=0;i<(1<<m);++i)dp[i][0]=1;
	for(int i=1;i<n;++i){
		swap(a,b);
		for(int now=0;now<(1<<m);++now){// 1:open, 0:close
			dp[now][a]=0;
			fill(tmp,tmp+15,0);//0:0,1 1:1,2 ... 14:14,15
			t=now,pos=0;
			while(t){
				if(t&1){
					++tmp[pos];
					if(pos-1>=0)++tmp[pos-1];
				}
				++pos;
				t>>=1;
			}
			for(int last=0;last<(1<<m);++last){
				fill(sum,sum+15,0);
				t=last,pos=0;
				while(t){
					if(t&1){
						++sum[pos];
						if(pos-1>=0)++sum[pos-1];
					}
					++pos;
					t>>=1;
				}
				flag=1;
				for(int j=0;j<m-1;++j)if(sum[j]+tmp[j]<2){flag=0;break;}
				if(flag){
					/*out=now;
					cout<<out<<'\n';
					out=last;
					cout<<out<<"\n\n";*/
					//cout<<now<<' '<<last<<'\n';
					add(dp[now][a],dp[last][b]);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<m);++i){
		add(ans,dp[i][a]);
	}
	cout<<ans<<'\n';
}
//40分的解
