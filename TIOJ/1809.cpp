#include <iostream>
#include <set>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int const N=1e7+10;
int n,m,q;
set<pii> st;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m>>q;
	int u,v;
	while(m--)cin>>u>>v,st.insert({min(u,v),max(u,v)});
	while(q--)cin>>u>>v,cout<<((st.find({min(u,v),max(u,v)})==st.end())?"no\n":"yes\n");
}
