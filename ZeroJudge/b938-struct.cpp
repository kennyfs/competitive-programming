#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
struct node{
    bool dead=0;
    int next=0;
    void operator+=(int n){
        next=n;
    }
};
int const N=1e6+10;
int n,m;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>m;
	node d[n+1];
	for(int i=1;i<=n-1;++i){
		d[i]+=i+1;
	}
	int killer;
	for(int i=0;i<m;++i){
		cin>>killer;
		if(d[killer].dead||d[killer].next==0){
			cout<<"0u0 ...... ?\n";
			continue;
		}
		cout<<d[killer].next<<'\n';
		d[d[killer].next].dead=1;
		d[killer]+=d[d[killer].next].next;
	}
}
//struct的鏈結串列
