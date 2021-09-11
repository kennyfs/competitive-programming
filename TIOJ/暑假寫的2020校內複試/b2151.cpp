#include <iostream>
#define ll long long
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll const INF=1ll<<60;
int const N=200+10;
int n,m,s;
ll t;
int c[N];
struct matrix{
	ll m[N][N];
	matrix operator*(matrix& o){
		matrix ans;
		fill(&ans.m[0][0],&ans.m[0][0]+N*N,-INF);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k){
					ans.m[i][j]=max(ans.m[i][j],m[i][k]+o.m[k][j]);
				}
			}
		}
		return ans;
	}
};
void fastpow(matrix& mat){
	matrix a;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)a.m[i][j]=(i==j)?0:-INF;
	for(;t;t>>=1){
		if(t&1)a=a*mat;
		mat=mat*mat;
	}
	mat=a;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>s>>t;
	for(int i=1;i<=n;++i)cin>>c[i];
	int u,v;
	matrix mat;
	fill(&mat.m[0][0],&mat.m[0][0]+N*N,-INF);
	for(int i=0;i<m;++i){
		cin>>u>>v;
		mat.m[u][v]=c[v];
	}
	fastpow(mat);
	ll ans=-INF;
	for(int i=1;i<=n;++i)ans=max(ans,mat.m[s][i]);
	cout<<ans<<'\n';
}
