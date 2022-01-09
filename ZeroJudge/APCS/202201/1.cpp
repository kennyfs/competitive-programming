#include <iostream>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,d;
int main(){
	Hirasawa_Yui_My_Wife
	cin>>n>>d;
	n--;
	int last,total=0,now;
	bool have=1;
	cin>>last
	while(n--){
		cin>>now
		if(have&&now-last>=d){
			have=0;
			total+=now-last;
			last=now;
		}else if((!have)&&last-now>=d){
			have=1;
			last=now;
		}
	}
	cout<<total;
}
