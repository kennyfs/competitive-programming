#include <iostream>
#include <vector>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n;
vector<int> infect;
bool q(int l,int r){
	cout<<"? "<<r-l+1<<' ';
	for(int i=l;i<r;++i){
		cout<<i<<' ';
	}
	cout<<r<<endl;
	int ans;
	cin>>ans;
	return ans;
}
void solve(int l,int r){
	if(!q(l,r))return;
	if(l==r){infect.push_back(l);return;}
	int m=(l+r)>>1;
	solve(l,m);
	solve(m+1,r);
}
void output(){
	cout<<"! "<<infect.size()<<' ';
	for(int i:infect)
		cout<<i<<' ';
	cout<<endl;
}
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n;
	int cut=100;
	for(int i=1;i<=cut;++i){
		if(n*(i-1)/cut==n*i/cut)continue;
		solve(n*(i-1)/cut+1,n*i/cut);
	}
	//solve(1,n);
	output();
}
