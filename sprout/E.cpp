#include <iostream>
using namespace std;
const int N=15,M=1.6e3+10,ANS=5e3;
int n,m,tot;
struct shi{
	int type;//0:scalar,1:not,2:and,3:or
	int num;
	shi *lc=NULL,*rc=NULL;
};
ostream& operator<<(ostream& s,shi &a){
	switch(a.type){
		case 0:
			s<<a.num<<' ';
			tot++;
			break;
		case 1:
			s<<"not ( "<<a.lc<<") ";
			break;
		case 2:
			exit(5);
		case 3:
			s<<"( "<<a.lc<<") or ( "<<a.rc<<") ";
	}
	return s;
}
int main(){
	cin>>n>>m;
}
