/*           OJDL TestCase Generater             */
/*  Made by FHVirus with patience for cin/cout   */
/*
How this works:
1.  Generate a file (testcase#.in)
2.  Read that file as input and solve,
    output to another file(testcase#.out)

How to use it:
0.  Put this program into a folder where
    you want to store the testcases.
1.  Input number of subtasks
2.  For each subtask, input the number of
    desired testcase for the subtask, then
    the arguments for generate().
3.  Done!
*/
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "/home/kenny/Desktop/jngen.h"
using namespace std;
// For generate(), you can add additional arguments
// for generating a testcase.
// But for solve(), just write a normal solution
// like that in main() for most of the time.
void generate(ofstream &cout,int sz=500,int zeroper=40,bool zero=1){
	//0:無限制
	//1:m=n-1
	//2:t_i相同
	int n;
	n=rnd.next(2,(int)5e2);
	n=sz;
	int sol[n],para[n][n];
	for(int i=0;i<n;++i){
		sol[i]=rnd.next((int)-1e3,(int)1e3);
		for(int j=0;j<n;++j){
			para[i][j]=rnd.next((int)-1e3,(int)1e3);
			if(rnd.next(1,100)<=zeroper)para[i][j]=0;
		}
	}
	if(zero){
		for(int j=0;j<n;++j){
			if(rnd.next(1,500)<=20){
				for(int i=0;i<n;++i)para[i][j]=0;
                sol[j]=8e7;
			}
		}
	}
	for(int i=0;i<n;++i){
        if(sol[i]!=8e7)std::cout<<i<<' '<<sol[i]<<'\n';
        else{
            std::cout<<"Hirasawa Yui So Cute\n";
        }
    }
	cout<<n<<'\n';
	for(int i=0;i<n;++i){
		long long sum=0;
		for(int j=0;j<n;++j){
			cout<<para[i][j]<<' ';
			sum+=1ll*para[i][j]*sol[j];
			if(sum>1e18||sum<-1e18)std::cout<<"toobig"<<endl;
		}
		cout<<sum<<'\n';
	}
}
int main(){
    int st,ed,sz;
    cin>>sz;
    cin>>st>>ed;
	for(int i=st;i<=ed;++i){
		string in = to_string(i) + ".in";
		{
			ofstream tsezi;
			tsezi.open(in);
			generate(tsezi,sz,50,1);
			tsezi.close();
		}
    }
    return 0;
}
