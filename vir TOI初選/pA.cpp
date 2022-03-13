#include <cstdio>
using namespace std;
int main(){
	double a1,b1,a2,b2;
	scanf("%lg",&a1);
	scanf("%lg",&a2);
	scanf("%lg",&b1);
	scanf("%lg",&b2);
	a2-=a1;b2-=b1;
	double x=(-b2)/a2;
	double y=a1*x+b1;
	x+=(x<0?-0.001:0),y+=(y<0?-0.001:0);
	printf("%.2f\n%.2f\n",x,y);
}
