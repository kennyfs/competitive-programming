#include <bits/stdc++.h>
using namespace std;
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=156;
int n,m;
char s[N],c;
bool e[N][N],rev[N];
deque<int> deq;
int main(){
    Hirasawa_Yui_My_Wife
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
		    cin>>c;
			if(c-'0'){
				e[i][j]=1;
				rev[i]^=1;
			}
		}
	}
	for(int j=1;j<=m;++j)cin>>s[j];
	for(int i=n;i>=1;--i){
		while(!deq.empty())deq.pop_front();
		for(int j=m;j>=1;--j){
			if(e[i][j])
				deq.push_back(s[j]);
			else
				deq.push_front(s[j]);
		}
		for(int j=1;j<=m;++j)s[j]=deq.front(),deq.pop_front();
		if(rev[i]){
			for(int j=1;j<=m/2;++j){
				swap(s[j],s[j+m/2+m%2]);
			}
		}
	}
	for(int j=1;j<=m;++j)cout<<s[j];
}
