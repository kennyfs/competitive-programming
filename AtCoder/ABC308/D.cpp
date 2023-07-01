#include <bits/stdc++.h>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int N=500+156;
int h,w;
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char s[N][N];
bool ok[N][N];
string snuke="snuke";
void dfs(int x,int y,int id){
	if(ok[x][y])return;
	ok[x][y]=1;
	for(int i=0;i<4;++i){
		int dx=x+d[i][0],dy=y+d[i][1];
		if(dx<1||dy<1||dx>h||dy>w)continue;
		if(s[dx][dy]==snuke[(id+1)%5])dfs(dx,dy,(id+1)%5);
	}
}
signed main(){
	Hirasawa_Yui_My_Wife
	cin>>h>>w;
	for(int i=1;i<=h;++i)
		for(int j=1;j<=w;++j)
			cin>>s[i][j];
	if(s[1][1]=='s')dfs(1,1,0);
	else{cout<<"No\n";return 0;}
	if(ok[h][w])cout<<"Yes\n";
	else cout<<"No\n";
}
