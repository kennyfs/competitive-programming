#include <iostream>
#include <utility>
#include <cstring>
#include <stack>
#define pii pair<int,int>
#define X first
#define Y second
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e3+10;
int n,m;
int sx,sy,ex,ey;
bool vis[N][N];
char ch[N][N];
int nxt[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
pii cord[N*N];
int last[N*N],mv[N*N];
string i2w="DULR";
stack<char> ans;
void print(int now){
	while(now){
		ans.push(i2w[mv[now]]);
		now=last[now];
	}
	cout<<ans.size()<<'\n';
	while(!ans.empty())cout<<ans.top(),ans.pop();
	cout<<'\n';
}
int main(){
	Hirasawa_Yui_My_Wife
    cin>>n>>m;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){cin>>ch[i][j];if(ch[i][j]=='A')cord[0]={i,j},vis[i][j]=1;}
	memset(vis,0,sizeof(vis));
	int tail=1,head=0;
	while(head<tail){
		for(int i=0;i<4;++i){
			int tx=cord[head].X+nxt[i][0],ty=cord[head].Y+nxt[i][1];
			if(tx<0||tx>=n||ty<0||ty>=m||ch[tx][ty]=='#'||vis[tx][ty])continue;
			vis[tx][ty]=1;
			cord[tail]={tx,ty};
			mv[tail]=i;
			last[tail]=head;
			if(ch[tx][ty]=='B'){cout<<"YES\n";print(tail);return 0;}
			++tail;
		}
		++head;
	}
	cout<<"NO\n";
}
//BFS
