#include <iostream>
#include <iomanip>
#define Hirasawa_Yui_My_Wife ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool leap(int y){
	if(y%400==0)return 1;
	if(y%100==0)return 0;
	if(y%4==0)return 1;
	return 0;
}
int daysinmonth(int y,int m){
	if(leap(y)&&m==2)return 29;
	return days[m];
}
struct date{
	int y,m,d;
	void update(){
		if(m==13){
			++y;
			m=1;
		}
	}
	void operator+=(int days){
		while(d+days>daysinmonth(y,m)){
			days-=daysinmonth(y,m);
			++m;
			update();
		}
		d+=days;
	}
};
ostream& operator<<(ostream& s,date& da){
	s<<setw(4)<<setfill('0')<<da.y<<'/'<<setw(2)<<setfill('0')<<da.m<<'/'<<setw(2)<<setfill('0')<<da.d;
	return s;
}
int gcd(int a,int b){
	return (b)?gcd(b,a%b):a;
}
int lcm(int a,int b){
	if(a>b)swap(a,b);
	return b*(a/gcd(a,b));
}
int main(){
	Hirasawa_Yui_My_Wife
	int n,tmp;
	cin>>n;
	int a=1;
	for(int i=0;i<n;++i){
		cin>>tmp;
		a=lcm(a,tmp);
	}
	char p;
	int y,m,d;
	date da;
	cin>>y>>p>>m>>p>>d;
	da.y=y;
	da.m=m;
	da.d=d;
	da+=a;
	cout<<da<<'\n';
}
