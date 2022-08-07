
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cstring>
#include "/home/kenny/Desktop/jngen.h"
using namespace std;
// For generate(), you can add additional arguments
// for generating a testcase.
// But for solve(), just write a normal solution
// like that in main() for most of the time.
const int N=20e3+10;
void generate(ofstream &cout,int op=1){
	int n;
	switch(op){
		case 3:
		n=rnd.next(4500,5000);
		break;
		case 4:
		n=rnd.next(150000000,200000000);
		break;
	}
	cout<<n<<'\n';
}
int main(){
    int st,ed,op;
    cin>>op;
    cin>>st>>ed;
	for(int i=st;i<=ed;++i){
		string in = to_string(i) + ".in";
		{
			cout<<i<<':';
			ofstream tsezi;
			tsezi.open(in);
			generate(tsezi,op);
			tsezi.close();
			cout<<endl;
		}
    }
    return 0;
}
