#include <iostream>
#include <set>
#include <cstring>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
short g[3][3];
short l,w,t;
bool H[200000];
int result(){
	for(int c=1;c<=2;++c)
	if((g[0][0]==c&&g[0][1]==c&&g[0][2]==c)||(g[1][0]==c&&g[1][1]==c&&g[1][2]==c)||(g[2][0]==c&&g[2][1]==c&&g[2][2]==c)||(g[0][0]==c&&g[1][0]==c&&g[2][0]==c)||(g[0][1]==c&&g[1][1]==c&&g[2][1]==c)||(g[0][2]==c&&g[1][2]==c&&g[2][2]==c)||(g[0][0]==c&&g[1][1]==c&&g[2][2]==c)||(g[2][0]==c&&g[1][1]==c&&g[0][2]==c))return c;
	for(int x=0;x<3;++x)
		for(int y=0;y<3;++y)
			if(g[x][y]==0)return 0;
	return -1;//-1 for t
}
bool h(){
	int ans=0;
	for(int x=0;x<3;++x)
		for(int y=0;y<3;++y)
			ans=ans*3+g[x][y];
	if(H[ans])return 1;
	H[ans]=1;return 0;
}
void dfs(int c){
	int res=result();
	switch(res){
		case 1:
			if(!h())++w;
			return;
		case 2:
			if(!h())++l;
			return;
		case -1:
			if(!h())++t;
			return;
	}
	for(int x=0;x<3;++x){
		for(int y=0;y<3;++y){
			if(!g[x][y]){
				g[x][y]=c;
				dfs(!(c-1)+1);
				g[x][y]=0;
			}
		}
	}
}
int main(){
	Hirasawa_Yui_My_Wife
	string s;
	cin>>s;
	memset(H,0,sizeof(H));
	memset(g,0,sizeof(g));
	w=l=t=0;
	char c;
	int O=0,X=0;
	for(int x=0;x<3;++x){
		for(int y=0;y<3;++y){
			c=s[x*3+y];
			if(c=='-')g[x][y]=0;
			if(c=='O')g[x][y]=1,++O;
			if(c=='X')g[x][y]=2,++X;
		}
	}
	int res=result();
	switch(res){
		case 1:
			cout<<"1 1 0 0\n";
			return 0;
		case 2:
			cout<<"1 0 1 0\n";
			return 0;
		case -1:
			cout<<"1 0 0 1\n";
			return 0;
	}
	int first=(O!=X)+1;
	dfs(first);
	cout<<w+l+t<<' '<<w<<' '<<l<<' '<<t<<'\n';
}
//暴力，debug超久
